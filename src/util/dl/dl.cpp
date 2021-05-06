#include "dl.hpp"
void dlmgr::LoadBar(unsigned curr_val, unsigned max_val, unsigned bar_width)
{
	if ((curr_val != max_val) && (curr_val % (max_val / 100) != 0))
		return;

	double   ratio = curr_val / (double)max_val;
	unsigned bar_now = (unsigned)(ratio * bar_width);

	cout << "\r" << setw(3) << (unsigned)(ratio * 100.0) << "% [";
	for (unsigned curr_val = 0; curr_val < bar_now; ++curr_val)
		cout << "=";
	for (unsigned curr_val = bar_now; curr_val < bar_width; ++curr_val)
		cout << " ";
	cout << "]" << flush;
}

void dlmgr::download(char* url, char* path) {
	std::cout << "[d] downloading started\n";
	std::cout << "[d] url: " << url << '\n';
	std::cout << "[d] path: " << path << '\n';
	DeleteUrlCacheEntryA(url);
	CallbackHandler cbHandler;
	IBindStatusCallback* pBindStatusCallback = NULL;
	cbHandler.QueryInterface(IID_IBindStatusCallback, reinterpret_cast<void**>(&pBindStatusCallback));
	HRESULT hr = URLDownloadToFileA(
		NULL,
		url,
		path,
		0,
		pBindStatusCallback);
	if (SUCCEEDED(hr)) {
		std::cout << "[d] download successful\n";
	}
}

void dlmgr::download(const char* url, const char* path) {
	std::cout << "[d] downloading started\n";
	std::cout << "[d] url: " << url << '\n';
	std::cout << "[d] path: " << path << '\n';
	DeleteUrlCacheEntryA(url);
	CallbackHandler cbHandler;
	IBindStatusCallback* pBindStatusCallback = NULL;
	cbHandler.QueryInterface(IID_IBindStatusCallback, reinterpret_cast<void**>(&pBindStatusCallback));
	HRESULT hr = URLDownloadToFileA(
		NULL,
		url,
		path,
		0,
		pBindStatusCallback);
	if (SUCCEEDED(hr)) {
		std::cout << "[d] download successful\n";
	}
}