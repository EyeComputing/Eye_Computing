#pragma once

#include <windows.h>
#include <vector>
#include "eyex/EyeX.h"
#include <mutex>

// 데이터 스트림을 제공하는 global interactor ID
static const TX_STRING InteractorId = "Twilight Sparkle";	

static TX_HANDLE g_hGlobalInteractorSnapshot = TX_EMPTY_HANDLE; // GazeDataStream 을 받기위함

class EyeXGaze
{
public:
	// ActivatableRegion 구조체 정의
	struct ActivatableRegion
	{
		int id;
		RECT bounds;

		ActivatableRegion(int paramId, RECT paramBounds) : id(paramId), bounds(paramBounds) {}
	};
	
	//생성자
	EyeXGaze();	
	
	//소멸자
	virtual ~EyeXGaze();

	//Connection을 시작한다. 주어진 핸들로 윈도우에 적용한다. 
	void Init(HWND hWnd, UINT statusChangedMessage, UINT focusedRegionChangedMessage, UINT regionActivatedMessage);

	//activatable region들을 찾아서 update를 한다
	void SetActivatableRegions(const std::vector<ActivatableRegion>& regions);

	// 해당 지역을 동작시킨다. (direct click)
	// 이 메서드를 사용하여 클릭을 구현할 수 있으므로, 수정하려면 이 부분 수정이 필요함.
	void TriggerActivation();

//    TX_REAL getGazeEye_X();
  //  TX_REAL getGazeEye_Y();
	TX_REAL getFixEye_X();
	TX_REAL getFixEye_Y();
private:
	//static TX_REAL GazeEye_X;
	//static TX_REAL GazeEye_Y;
	static TX_REAL FixEye_X;
	static TX_REAL FixEye_Y;
	INT fps;
	TX_CONTEXTHANDLE _hContext;
	TX_TICKET _connectionStateChangedTicket;
	TX_TICKET _queryHandlerTicket;
	TX_TICKET _eventHandlerTicket;
	std::mutex _mutex;
	std::vector<ActivatableRegion> _regions;
	// attached window and custom messages(init 수행할때 넘겨지는 인수들)
	HWND _hWnd;
	UINT _statusChangedMessage;
	UINT _focusRegionChangedMessage;
	UINT _regionActivatedMessage;

	// GazeDataStream 다루는 메서드
	BOOL InitializeGlobalInteractorSnapshot(TX_CONTEXTHANDLE hContext);
	static void TX_CALLCONVENTION OnSnapshotCommitted(TX_CONSTHANDLE hAsyncData, TX_USERPARAM param);
	void OnEngineConnectionStateChanged(TX_CONNECTIONSTATE connectionState);
	//void OnGazeDataEvent(TX_HANDLE hGazeDataBehavior);
	void OnFixationDataEvent(TX_HANDLE hFixationDataBehavior);
	void TX_CALLCONVENTION FixHandleEvent(TX_CONSTHANDLE hAsyncData);
	//void TX_CALLCONVENTION GazeHandleEvent(TX_CONSTHANDLE hAsyncData);

	//버튼 예제의 메서드들, 중복된 메서드들은 제거 

	// register handlers for notification from the engine
	bool RegisterConnectionStateChangedHandler();
	bool RegisterQueryHandler();
	bool RegisterEventHandler();

	// event handlers
	void HandleQuery(TX_CONSTHANDLE hAsyncData);
	void HandleEvent(TX_CONSTHANDLE hAsyncData);
	void HandleActivatableEvent(TX_HANDLE hEvent, int interactorId);
	void OnActivationFocusChanged(TX_HANDLE hBehavior, int interactorId);
	void OnActivated(TX_HANDLE hBehavior, int interactorId);

	static bool QueryIsForWindowId(TX_HANDLE hQuery, const TX_CHAR* windowId);

};

