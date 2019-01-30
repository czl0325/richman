#pragma once
#pragma comment(lib,"winmm.lib")
#include <MMSystem.h>
class CTool
{
public:
	CTool(void);
	~CTool(void);
	UINT m_uiMIDIPlayerID;
	BOOL FileToBitmap(HBITMAP& hBitmap,char* fileName,int Width,int Height);
	int DrawMapText(CString text, int x, int y, COLORREF color, int size, HDC hdc);
	int DrawMapText(const char* text, int x, int y, COLORREF color, int size, HDC hdc);
	void PlayMIDISong(LPTSTR szMIDIFileName=(""), BOOL bRestart=TRUE);
	void PauseMIDISong();
	void CloseMIDIPlayer();
};
