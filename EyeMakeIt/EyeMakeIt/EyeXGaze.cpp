
#include"stdafx.h"
#include "EyeXGaze.h"
#include <cassert>
#include <objidl.h>
#include <gdiplus.h>
#include <cstdint>
#include <windows.h>
#include <tchar.h>

#pragma comment(lib, "Tobii.EyeX.Client.lib")

#if INTPTR_MAX == INT64_MAX
#define WINDOW_HANDLE_FORMAT "%lld"
#else
#define WINDOW_HANDLE_FORMAT "%d"
#endif

#define ErrorD 21


// Data Stream을 받는 변수 초기화
//TX_REAL EyeXGaze::GazeEye_X = 0;
//TX_REAL EyeXGaze::GazeEye_Y = 0;
TX_REAL EyeXGaze::FixEye_X = 0;
TX_REAL EyeXGaze::FixEye_Y = 0;

EyeXGaze::EyeXGaze()
	: _hWnd(nullptr), _statusChangedMessage(0), _focusRegionChangedMessage(0), _regionActivatedMessage(0)
{
	txInitializeEyeX(TX_EYEXCOMPONENTOVERRIDEFLAG_NONE, nullptr, nullptr, nullptr, nullptr);// client library사용을위한 init

	txCreateContext(&_hContext, TX_FALSE);													// context 생성
	InitializeGlobalInteractorSnapshot(_hContext);											// global interactor snapshot 생성 ( 나중에 gaze data stream 받기위함 )

		
	// 핸들러 등록
	RegisterConnectionStateChangedHandler();	
	RegisterQueryHandler();
	RegisterEventHandler();

	
}
// TX_CONNECTIONSTATECHANGEDCALLBACK

EyeXGaze::~EyeXGaze()
{	
	//connection disable 및 global interactor release
	txDisableConnection(_hContext);
	txReleaseObject(&g_hGlobalInteractorSnapshot);

	// context shutdown 및 release
	txShutdownContext(_hContext, TX_CLEANUPTIMEOUT_DEFAULT, TX_FALSE);
	txReleaseContext(&_hContext);

	// client library 연결 해제
	txUninitializeEyeX(); 
}

void EyeXGaze::Init(HWND hWnd, UINT statusChangedMessage, UINT focusRegionChangedMessage, UINT regionActivatedMessage)
{
	// window handle
	_hWnd = hWnd;

	//status messages
	_statusChangedMessage = statusChangedMessage;
	_focusRegionChangedMessage = focusRegionChangedMessage;
	_regionActivatedMessage = regionActivatedMessage;

	// connect to the EyeX Engine - after making context, handler, global interacotr etc.
	if (txEnableConnection(_hContext) != TX_RESULT_OK)
	{
		PostMessage(_hWnd, _statusChangedMessage, false, 0);	// 메시지에 false를 담아보냄		
	}
}



void EyeXGaze::SetActivatableRegions(const std::vector<ActivatableRegion>& regions)
{
	std::lock_guard<std::mutex> lock(_mutex);

	_regions.assign(regions.begin(), regions.end());
}

void EyeXGaze::TriggerActivation()
{
	TX_HANDLE command(TX_EMPTY_HANDLE);

	// set command in context as click activation button.
	txCreateActionCommand(_hContext, &command, TX_ACTIONTYPE_ACTIVATE);

	//execute command
	txExecuteCommandAsync(command, NULL, NULL);
	txReleaseObject(&command);
}

/*
TX_REAL EyeXGaze::getGazeEye_X()
{
	return GazeEye_X;
}

TX_REAL EyeXGaze::getGazeEye_Y()
{
	return GazeEye_Y;
}
*/
TX_REAL EyeXGaze::getFixEye_X()
{
	return FixEye_X;
}

TX_REAL EyeXGaze::getFixEye_Y()
{
	return FixEye_Y;
}

BOOL EyeXGaze::InitializeGlobalInteractorSnapshot(TX_CONTEXTHANDLE hContext)
{
	TX_HANDLE hInteractor = TX_EMPTY_HANDLE;
	// Gaze데이터 출력을 위한 변수 LIGHTLY FILTERED 모드
//	TX_GAZEPOINTDATAPARAMS params = { TX_GAZEPOINTDATAMODE_LIGHTLYFILTERED };

	// Fix데이터 출력을 위한 변수 SENSITIVE 모드
	TX_FIXATIONDATAPARAMS fparams = { TX_FIXATIONDATAMODE_SENSITIVE };	// SLOW 도 있음
	BOOL success;

	// global interactor 생성 
	success = txCreateGlobalInteractorSnapshot(
		hContext,
		InteractorId,
		&g_hGlobalInteractorSnapshot,
		&hInteractor) == TX_RESULT_OK; 

	// behavior를 gaze point data로 설정
	//success &= txCreateGazePointDataBehavior(hInteractor, &params) == TX_RESULT_OK; 

	// behavior를 fixation data로 설정
	success &= txCreateFixationDataBehavior(hInteractor, &fparams) == TX_RESULT_OK;

	// interactor 사용후 release
	txReleaseObject(&hInteractor);

	return success;
}

void TX_CALLCONVENTION EyeXGaze::OnSnapshotCommitted(TX_CONSTHANDLE hAsyncData, TX_USERPARAM param)
{
	// 결과물을 체크하는 함수 부분
	
	TX_RESULT result = TX_RESULT_UNKNOWN;
	txGetAsyncDataResultCode(hAsyncData, &result);
	assert(result == TX_RESULT_OK || result == TX_RESULT_CANCELLED);

}

void EyeXGaze::OnEngineConnectionStateChanged(TX_CONNECTIONSTATE connectionState)
{
	switch (connectionState)
	{
	case TX_CONNECTIONSTATE_CONNECTED: 
		{
			// commit snapshot to EyeX Engine
			txCommitSnapshotAsync(g_hGlobalInteractorSnapshot, OnSnapshotCommitted, NULL);
			
			
		}
		PostMessage(_hWnd, _statusChangedMessage, true, 0);
		break;

	case TX_CONNECTIONSTATE_DISCONNECTED:
	case TX_CONNECTIONSTATE_TRYINGTOCONNECT:
	case TX_CONNECTIONSTATE_SERVERVERSIONTOOLOW:
	case TX_CONNECTIONSTATE_SERVERVERSIONTOOHIGH:
		PostMessage(_hWnd, _statusChangedMessage, false, 0);
		break;
	}
};
/*
void EyeXGaze::OnGazeDataEvent(TX_HANDLE hGazeDataBehavior)
{
	// gaze point data를 저장하기위한 구조체
	TX_GAZEPOINTDATAEVENTPARAMS eventParams;

	
	typedef struct {
    TX_GAZEPOINTDATAMODE GazePointDataMode;
    TX_REAL Timestamp;
    TX_REAL X;       
    TX_REAL Y;
} TX_GAZEPOINTDATAEVENTPARAMS;
	

	if (txGetGazePointDataEventParams(hGazeDataBehavior, &eventParams) == TX_RESULT_OK)
	{
		//출력
		GazeEye_X = eventParams.X;
		GazeEye_Y = eventParams.Y;
		InvalidateRect(_hWnd, nullptr, false);
	}
	else
	{
		// 에러출력
	}
}
*/
void EyeXGaze::OnFixationDataEvent(TX_HANDLE hFixationDataBehavior)
{
	TX_FIXATIONDATAEVENTPARAMS eventParams;
	TX_FIXATIONDATAEVENTTYPE eventType;
	char* eventDescription;

	if (txGetFixationDataEventParams(hFixationDataBehavior, &eventParams) == TX_RESULT_OK) {
		eventType = eventParams.EventType;

		eventDescription = (eventType == TX_FIXATIONDATAEVENTTYPE_DATA) ? "Data"
			: ((eventType == TX_FIXATIONDATAEVENTTYPE_END) ? "End"
				: "Begin");
		
		if (fps == 5)
		{
			
			if (FixEye_X == 0 && FixEye_Y == 0)
			{
				FixEye_X = eventParams.X;
				FixEye_Y = eventParams.Y;
				fps = 0;
			}
			else
			{
				if (eventParams.X < FixEye_X - ErrorD || eventParams.X > FixEye_X + ErrorD || eventParams.Y < FixEye_Y - ErrorD || eventParams.Y > FixEye_Y + ErrorD)
				{
					FixEye_X = eventParams.X;
					FixEye_Y = eventParams.Y;
					fps = 0;
				}
				else
					fps = 0;
			}
			
			//for (int i = 0; i < 5; i++)
			//{
			//FixEye_X = eventParams.X;
			//FixEye_Y = eventParams.Y;
			//fps = 0;
				SetCursorPos(FixEye_X, FixEye_Y);

			//}

		
			
		}
		else
			fps++;
	}
	else {
		
	}
}


void TX_CALLCONVENTION EyeXGaze::FixHandleEvent(TX_CONSTHANDLE hAsyncData)
{
	TX_HANDLE hEvent = TX_EMPTY_HANDLE;
	TX_HANDLE hBehavior = TX_EMPTY_HANDLE;

	// DataContent를 hEvent에 저장
	txGetAsyncDataContent(hAsyncData, &hEvent);
	//event에서 behavior를 해당 타입대로 추출하여 hBehavior변수에 저장

	if (txGetEventBehavior(hEvent, &hBehavior, TX_BEHAVIORTYPE_FIXATIONDATA) == TX_RESULT_OK)
	{
		OnFixationDataEvent(hBehavior);
		txReleaseObject(&hBehavior);
	}
	txReleaseObject(&hEvent);
}
/*
void TX_CALLCONVENTION EyeXGaze::GazeHandleEvent(TX_CONSTHANDLE hAsyncData)
{
	TX_HANDLE hEvent = TX_EMPTY_HANDLE;
	TX_HANDLE hBehavior = TX_EMPTY_HANDLE;

	// DataContent를 hEvent에 저장
	txGetAsyncDataContent(hAsyncData, &hEvent);
	//event에서 behavior를 해당 타입대로 추출하여 hBehavior변수에 저장
	if (txGetEventBehavior(hEvent, &hBehavior, TX_BEHAVIORTYPE_GAZEPOINTDATA) == TX_RESULT_OK)
	{
		OnGazeDataEvent(hBehavior);
		txReleaseObject(&hBehavior);
	}
	txReleaseObject(&hEvent);
}
*/
bool EyeXGaze::RegisterConnectionStateChangedHandler()
{
	auto connectionStateChangedTrampoline = [](TX_CONNECTIONSTATE connectionState, TX_USERPARAM userParam)
	{
		static_cast<EyeXGaze*>(userParam)->OnEngineConnectionStateChanged(connectionState);
	};

	// 해당 context에 ticket을 지정하고 세 번째 인자를 state가 change될 때마다 호출한다.
	bool success = txRegisterConnectionStateChangedHandler(_hContext, &_connectionStateChangedTicket, connectionStateChangedTrampoline, this) == TX_RESULT_OK;
	return success;
}

bool EyeXGaze::RegisterEventHandler()
{
	auto eventHandlerTrampoline = [](TX_CONSTHANDLE hObject, TX_USERPARAM userParam)
	{
		//static_cast<EyeXGaze*>(userParam)->GazeHandleEvent(hObject);
		static_cast<EyeXGaze*>(userParam)->FixHandleEvent(hObject);	//	Fixation
		static_cast<EyeXGaze*>(userParam)->HandleEvent(hObject);	//	Activatable Region

	};
	bool success = txRegisterEventHandler(_hContext, &_connectionStateChangedTicket, eventHandlerTrampoline, this) == TX_RESULT_OK;
	return success;
}

bool EyeXGaze::RegisterQueryHandler()
{
	auto queryHandlerTrampoline = [](TX_CONSTHANDLE hObject, TX_USERPARAM userParam)
	{
		static_cast<EyeXGaze*>(userParam)->HandleQuery(hObject);
	};
	bool success = txRegisterQueryHandler(_hContext, &_connectionStateChangedTicket, queryHandlerTrampoline, this) == TX_RESULT_OK;
	return success;
}

void EyeXGaze::HandleQuery(TX_CONSTHANDLE hAsyncData)
{
	std::lock_guard<std::mutex> lock(_mutex);

	TX_HANDLE hQuery(TX_EMPTY_HANDLE);			// query를 받기위한 핸들
	txGetAsyncDataContent(hAsyncData, &hQuery);	// asyncdatacontent를 hquery에 저장

	const int bufferSize = 20;
	TX_CHAR stringBuffer[bufferSize];

	// query 를 가지고 rectangular bounds 생성
	TX_HANDLE hBounds(TX_EMPTY_HANDLE);
	txGetQueryBounds(hQuery, &hBounds); // query의 bound 알아낸다
	TX_REAL pX, pY, pWidth, pHeight;
	txGetRectangularBoundsData(hBounds, &pX, &pY, &pWidth, &pHeight);// bound에서 rectangular한 좌표 추출
	txReleaseObject(&hBounds);
	Gdiplus::Rect queryBounds((INT)pX, (INT)pY, (INT)pWidth, (INT)pHeight); 

	// query 를 가지고 Snapshot 생성
	TX_HANDLE hSnapshot(TX_EMPTY_HANDLE);
	txCreateSnapshotForQuery(hQuery, &hSnapshot);

	TX_CHAR windowIdString[bufferSize];
	sprintf_s(windowIdString, bufferSize, WINDOW_HANDLE_FORMAT, _hWnd);
	
	if (QueryIsForWindowId(hQuery, windowIdString))
	{
		TX_ACTIVATABLEPARAMS params = { TX_FALSE };

		for (auto region : _regions)
		{
			Gdiplus::Rect regionBounds((INT)region.bounds.left,(INT)region.bounds.top,
				(INT)(region.bounds.right - region.bounds.left), 
				(INT)(region.bounds.bottom - region.bounds.top));

			if (queryBounds.IntersectsWith(regionBounds))
			{
				TX_HANDLE hInteractor(TX_EMPTY_HANDLE);

				sprintf_s(stringBuffer, bufferSize, "%d", region.id);

				TX_RECT bounds;
				bounds.X = region.bounds.left;
				bounds.Y = region.bounds.top;
				bounds.Width = region.bounds.right - region.bounds.left;
				bounds.Height = region.bounds.bottom - region.bounds.top;

				txCreateRectangularInteractor(hSnapshot, &hInteractor, stringBuffer, &bounds,
					TX_LITERAL_ROOTID, windowIdString);
				txCreateActivatableBehavior(hInteractor, &params);

				txReleaseObject(&hInteractor);
			}
		}
	}
	txCommitSnapshotAsync(hSnapshot, OnSnapshotCommitted, nullptr);
	txReleaseObject(&hSnapshot);
	txReleaseObject(&hQuery);
}

void EyeXGaze::HandleEvent(TX_CONSTHANDLE hAsyncData)
{
	TX_HANDLE hEvent(TX_EMPTY_HANDLE);
	txGetAsyncDataContent(hAsyncData, &hEvent);

	// NOTE. Uncomment the following line of code to view the event object. The same function can be used with any interaction object.
	//OutputDebugStringA(txDebugObject(hEvent));

	// read the interactor ID from the event.
	const int bufferSize = 20;
	TX_CHAR stringBuffer[bufferSize];
	TX_SIZE idLength(bufferSize);
	if (txGetEventInteractorId(hEvent, stringBuffer, &idLength) == TX_RESULT_OK)
	{
		int interactorId = atoi(stringBuffer);

		HandleActivatableEvent(hEvent, interactorId);
	}

	txReleaseObject(&hEvent);
}

void EyeXGaze::HandleActivatableEvent(TX_HANDLE hEvent, int interactorId)
{
	TX_HANDLE hActivatable(TX_EMPTY_HANDLE);
	if (txGetEventBehavior(hEvent, &hActivatable, TX_BEHAVIORTYPE_ACTIVATABLE) == TX_RESULT_OK)
	{
		TX_ACTIVATABLEEVENTTYPE eventType;
		if(txGetActivatableEventType(hActivatable,&eventType)==TX_RESULT_OK)
		{
			if (eventType == TX_ACTIVATABLEEVENTTYPE_ACTIVATED)
			{
				OnActivated(hActivatable, interactorId);
			}
			else if (eventType == TX_ACTIVATABLEEVENTTYPE_ACTIVATIONFOCUSCHANGED)
			{				
				OnActivationFocusChanged(hActivatable, interactorId);
			}
		}
	}
	txReleaseObject(&hActivatable);
}

void EyeXGaze::OnActivationFocusChanged(TX_HANDLE hBehavior, int interactorId)
{
	TX_ACTIVATIONFOCUSCHANGEDEVENTPARAMS eventData;
	TCHAR text[100];
	wsprintf(text, L"OnActivationFocus Changed function");
	MessageBox(GetFocus(), text, L"Testing", MB_OK);
	if (txGetActivationFocusChangedEventParams(hBehavior, &eventData) == TX_RESULT_OK)
	{
		if (eventData.HasActivationFocus)
		{
			PostMessage(_hWnd, _focusRegionChangedMessage, interactorId, 0);
		}
		else
		{
			PostMessage(_hWnd, _focusRegionChangedMessage, -1, 0);
		}
	}
}

void EyeXGaze::OnActivated(TX_HANDLE hBehavior, int interactorId)
{
	PostMessage(_hWnd, _regionActivatedMessage, interactorId, 0);
}

bool EyeXGaze::QueryIsForWindowId(TX_HANDLE hQuery, const TX_CHAR* windowId)
{
	const int bufferSize = 20;
	TX_CHAR buffer[bufferSize];

	TX_SIZE count;
	if (TX_RESULT_OK == txGetQueryWindowIdCount(hQuery, &count))	// 윈도우 아이디를 찾음
	{
		for (int i = 0; i < count; i++)
		{
			TX_SIZE size = bufferSize;
			if (TX_RESULT_OK == txGetQueryWindowId(hQuery, i, buffer, &size))
			{
				if (0 == strcmp(windowId, buffer))
				{
					return true;
				}
			}
		}
	}

}

/*
TCHAR text[100];
wsprintf(text, L"Complete Initialize EyeXGaze");
MessageBox(GetFocus(), text, L"Testing", MB_OK);
*/