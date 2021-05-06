#pragma once
#include "../../framework.hpp"
#include "define.hpp"
#include <WinInet.h>

using namespace std;

#ifdef _UNICODE
#define tcout wcout
#else
#define tcout cout
#endif

// Adapted from:
// Creating a progress bar in C/C++ (or any other console app.)
// http://www.rosshemsley.co.uk/2011/02/creating-a-progress-bar-in-c-or-any-other-console-app/
void LoadBar(unsigned curr_val, unsigned max_val, unsigned bar_width = 20)
{
	if ((curr_val != max_val) && (curr_val % (max_val / 100) != 0))
		return;

	double   ratio = curr_val / (double)max_val;
	unsigned bar_now = (unsigned)(ratio * bar_width);

	tcout << _T("\r") << setw(3) << (unsigned)(ratio * 100.0) << _T("% [");
	for (unsigned curr_val = 0; curr_val < bar_now; ++curr_val)
		tcout << _T("=");
	for (unsigned curr_val = bar_now; curr_val < bar_width; ++curr_val)
		tcout << _T(" ");
	tcout << _T("]") << flush;
}

class CallbackHandler : public IBindStatusCallback
{
private:
	int m_percentLast;

public:
	CallbackHandler() : m_percentLast(0)
	{
	}

	// IUnknown

	HRESULT STDMETHODCALLTYPE
		QueryInterface(REFIID riid, void** ppvObject)
	{

		if (IsEqualIID(IID_IBindStatusCallback, riid)
			|| IsEqualIID(IID_IUnknown, riid))
		{
			*ppvObject = reinterpret_cast<void*>(this);
			return S_OK;
		}

		return E_NOINTERFACE;
	}

	ULONG STDMETHODCALLTYPE
		AddRef()
	{
		return 2UL;
	}

	ULONG STDMETHODCALLTYPE
		Release()
	{
		return 1UL;
	}

	// IBindStatusCallback

	HRESULT STDMETHODCALLTYPE
		OnStartBinding(DWORD     /*dwReserved*/,
			IBinding* /*pib*/)
	{
		return E_NOTIMPL;
	}

	HRESULT STDMETHODCALLTYPE
		GetPriority(LONG* /*pnPriority*/)
	{
		return E_NOTIMPL;
	}

	HRESULT STDMETHODCALLTYPE
		OnLowResource(DWORD /*reserved*/)
	{
		return E_NOTIMPL;
	}

	HRESULT STDMETHODCALLTYPE
		OnProgress(ULONG   ulProgress,
			ULONG   ulProgressMax,
			ULONG   ulStatusCode,
			LPCWSTR /*szStatusText*/)
	{
		switch (ulStatusCode)
		{
		case BINDSTATUS_FINDINGRESOURCE:
			tcout << _T("Finding resource...") << endl;
			break;
		case BINDSTATUS_CONNECTING:
			tcout << _T("Connecting...") << endl;
			break;
		case BINDSTATUS_SENDINGREQUEST:
			tcout << _T("Sending request...") << endl;
			break;
		case BINDSTATUS_MIMETYPEAVAILABLE:
			tcout << _T("Mime type available") << endl;
			break;
		case BINDSTATUS_CACHEFILENAMEAVAILABLE:
			tcout << _T("Cache filename available") << endl;
			break;
		case BINDSTATUS_BEGINDOWNLOADDATA:
			tcout << _T("Begin download") << endl;
			break;
		case BINDSTATUS_DOWNLOADINGDATA:
		case BINDSTATUS_ENDDOWNLOADDATA:
		{
			int percent = (int)(100.0 * static_cast<double>(ulProgress)
				/ static_cast<double>(ulProgressMax));
			if (m_percentLast < percent)
			{
				LoadBar(percent, 100);
				m_percentLast = percent;
			}
			if (ulStatusCode == BINDSTATUS_ENDDOWNLOADDATA)
			{
				tcout << endl << _T("End download") << endl;
			}
		}
		break;

		default:
		{
			tcout << _T("Status code : ") << ulStatusCode << endl;
		}
		}
		// The download can be cancelled by returning E_ABORT here
		// of from any other of the methods.
		return S_OK;
	}

	HRESULT STDMETHODCALLTYPE
		OnStopBinding(HRESULT /*hresult*/,
			LPCWSTR /*szError*/)
	{
		return E_NOTIMPL;
	}

	HRESULT STDMETHODCALLTYPE
		GetBindInfo(DWORD*    /*grfBINDF*/,
			BINDINFO* /*pbindinfo*/)
	{
		return E_NOTIMPL;
	}

	HRESULT STDMETHODCALLTYPE
		OnDataAvailable(DWORD      /*grfBSCF*/,
			DWORD      /*dwSize*/,
			FORMATETC* /*pformatetc*/,
			STGMEDIUM* /*pstgmed*/)
	{
		return E_NOTIMPL;
	}

	HRESULT STDMETHODCALLTYPE
		OnObjectAvailable(REFIID    /*riid*/,
			IUnknown* /*punk*/)
	{
		return E_NOTIMPL;
	}
};