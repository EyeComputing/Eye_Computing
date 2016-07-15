#pragma once

#include <windows.h>
#include <vector>
#include "eyex/EyeX.h"
#include <mutex>

// ������ ��Ʈ���� �����ϴ� global interactor ID
static const TX_STRING InteractorId = "Twilight Sparkle";	

static TX_HANDLE g_hGlobalInteractorSnapshot = TX_EMPTY_HANDLE; // GazeDataStream �� �ޱ�����

class EyeXGaze
{
public:
	// ActivatableRegion ����ü ����
	struct ActivatableRegion
	{
		int id;
		RECT bounds;

		ActivatableRegion(int paramId, RECT paramBounds) : id(paramId), bounds(paramBounds) {}
	};
	
	//������
	EyeXGaze();	
	
	//�Ҹ���
	virtual ~EyeXGaze();

	//Connection�� �����Ѵ�. �־��� �ڵ�� �����쿡 �����Ѵ�. 
	void Init(HWND hWnd, UINT statusChangedMessage, UINT focusedRegionChangedMessage, UINT regionActivatedMessage);

	//activatable region���� ã�Ƽ� update�� �Ѵ�
	void SetActivatableRegions(const std::vector<ActivatableRegion>& regions);

	// �ش� ������ ���۽�Ų��. (direct click)
	// �� �޼��带 ����Ͽ� Ŭ���� ������ �� �����Ƿ�, �����Ϸ��� �� �κ� ������ �ʿ���.
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
	// attached window and custom messages(init �����Ҷ� �Ѱ����� �μ���)
	HWND _hWnd;
	UINT _statusChangedMessage;
	UINT _focusRegionChangedMessage;
	UINT _regionActivatedMessage;

	// GazeDataStream �ٷ�� �޼���
	BOOL InitializeGlobalInteractorSnapshot(TX_CONTEXTHANDLE hContext);
	static void TX_CALLCONVENTION OnSnapshotCommitted(TX_CONSTHANDLE hAsyncData, TX_USERPARAM param);
	void OnEngineConnectionStateChanged(TX_CONNECTIONSTATE connectionState);
	//void OnGazeDataEvent(TX_HANDLE hGazeDataBehavior);
	void OnFixationDataEvent(TX_HANDLE hFixationDataBehavior);
	void TX_CALLCONVENTION FixHandleEvent(TX_CONSTHANDLE hAsyncData);
	//void TX_CALLCONVENTION GazeHandleEvent(TX_CONSTHANDLE hAsyncData);

	//��ư ������ �޼����, �ߺ��� �޼������ ���� 

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

