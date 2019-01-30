#include "StdAfx.h"
#include "Tool.h"

CTool::CTool(void)
{
	m_uiMIDIPlayerID=0;
}

CTool::~CTool(void)
{
}
BOOL CTool::FileToBitmap(HBITMAP& hBitmap,char* fileName,int Width,int Height)
{
	CString str;
	hBitmap=(HBITMAP)LoadImageA(NULL,fileName,IMAGE_BITMAP,Width,Height,LR_LOADFROMFILE);
	if(hBitmap==NULL)
	{
		str.Format(TEXT("无法打开位图%s"),TCHAR(fileName));
		AfxMessageBox(str);
		return FALSE;
	}
	return TRUE;
}
int CTool::DrawMapText(CString text, int x, int y, 
					   COLORREF color, int size, HDC hdc)
{
	LOGFONT my_Font;
	memset(&my_Font,0,sizeof(my_Font));
	//lfCharSet制定字符集
	my_Font.lfCharSet=DEFAULT_CHARSET;
	my_Font.lfHeight=size;

	HFONT hFont;
	hFont=::CreateFontIndirect(&my_Font);
	SelectObject(hdc,hFont);

	SetTextColor(hdc,color);
	SetBkMode(hdc,TRANSPARENT);
	TextOut(hdc,x,y,text,text.GetLength());

	return 1;
}
int CTool::DrawMapText(const char* text, int x, int y, COLORREF color, int size, HDC hdc)
{
	LOGFONT my_Font;
	memset(&my_Font,0,sizeof(my_Font));
	//lfCharSet制定字符集
	my_Font.lfCharSet=DEFAULT_CHARSET;
	my_Font.lfHeight=size;

	HFONT hFont;
	hFont=::CreateFontIndirect(&my_Font);
	SelectObject(hdc,hFont);

	SetTextColor(hdc,color);
	SetBkMode(hdc,TRANSPARENT);
	TextOut(hdc,x,y,text,strlen(text));

	return 1;
}
void CTool::PlayMIDISong(LPTSTR szMIDIFileName, BOOL bRestart)
{
	// See if the MIDI player needs to be opened
	if (m_uiMIDIPlayerID == 0)
	{
		// Open the MIDI player by specifying the device and filename
		MCI_OPEN_PARMS mciOpenParms;
		mciOpenParms.lpstrDeviceType = "sequencer";
		mciOpenParms.lpstrElementName = szMIDIFileName;
		if (mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT,
			(DWORD_PTR)&mciOpenParms) == 0)
			// Get the ID for the MIDI player
			m_uiMIDIPlayerID = mciOpenParms.wDeviceID;
		else
			// There was a problem, so just return
			return;
	}

	// Restart the MIDI song, if necessary
	if (bRestart)
	{
		MCI_SEEK_PARMS mciSeekParms;
		if (mciSendCommand(m_uiMIDIPlayerID, MCI_SEEK, MCI_SEEK_TO_START,
			(DWORD_PTR)&mciSeekParms) != 0)
			// There was a problem, so close the MIDI player
			CloseMIDIPlayer();
	}

	// Play the MIDI song
	MCI_PLAY_PARMS mciPlayParms;
	if (mciSendCommand(m_uiMIDIPlayerID, MCI_PLAY, 0,
		(DWORD_PTR)&mciPlayParms) != 0)
		// There was a problem, so close the MIDI player
		CloseMIDIPlayer();
}

void CTool::PauseMIDISong()
{
	// Pause the currently playing song, if possible
	if (m_uiMIDIPlayerID != 0)
		mciSendCommand(m_uiMIDIPlayerID, MCI_PAUSE, 0, NULL);
}

void CTool::CloseMIDIPlayer()
{
	// Close the MIDI player, if possible
	if (m_uiMIDIPlayerID != 0)
	{
		mciSendCommand(m_uiMIDIPlayerID, MCI_CLOSE, 0, NULL);
		m_uiMIDIPlayerID = 0;
	}
}
