// ============================================================================
//
// This file contains the actions, conditions and expressions your object uses
// 
// ============================================================================
#include "Common.h"
//#include "SyncObjs.h"
///////////////////////////////////////////////////////////////////////////////
//typedef void TOnMidiInData (int aDeviceIndex, byte aStatus, byte aData1, byte aData2);
///////////////////////////////////////////////////////////////////////////////

//TMidi *MidiData;
bool OnMidiData;
int mData1, mData2, mStatus;

const string Note [] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
const bool IsFlat [] = { 0,	  1,    0,   1,    0,   0,   1,    0,   1,    0,   1,    0};

bool DoMidiInData (LPRDATA rdPtr, byte aStatus, byte aData1, byte aData2) {
    /*cardinal*/ DWORD lMsg = 0;
    MMRESULT lResult;
    HMIDIOUT lHandle;
    ///////////////////////////
		lHandle = rdPtr->outHandle[rdPtr->DeviceID_out];
    lMsg = aStatus + ( aData1 * 0x100 ) + ( aData2 * 0x10000 );
    lResult = midiOutShortMsg( lHandle, lMsg );

    if (lResult != MMSYSERR_NOERROR)
      MessageBox (GetActiveWindow(), "An Error has occurred: "+GetLastError(), "Error (midi.mfx)", MB_OK|MB_ICONERROR|MB_TOPMOST|MB_TASKMODAL);
      //raise Exception.Create( GetLastErrorText );
    return true;
  }

//void midiCallback (HMIDIIN *aMidiInHandle, UINT aMsg, DWORD aData, DWORD aMidiData, DWORD aTimeStamp)
static void CALLBACK midiCallback (HMIDIIN *aMidiInHandle, UINT aMsg, DWORD aData, DWORD aMidiData, DWORD aTimeStamp)
  {
		//string mess;
		//string sData, sMidiData, sMsg;
		//char Buf [100];
		//char Buf2 [100];
		//string mess;
    if (aMsg == MIM_DATA)
      {
        //DeviceIndex = aData;
        //MidiStatus = aMidiData & 0x000000FF;
        //MidiData1 = (aMidiData & 0x0000FF00) >> 8;
        //MidiData2 = (aMidiData & 0x00FF0000) >> 16;
        //OnMidiData = true;
				//rdPtrEx->OnMidiData = true;
				//sMsg = string((char *)aMsg);
				
				//( aMidiData and $0000FF00 ) shr 8

				//MidiData->MidiStatus = aMidiData & 0x000000FF;
				//MidiData->MidiData1 = (aMidiData & 0x0000FF00) >> 8;
				//MidiData->MidiData2 = (aMidiData & 0x00FF0000) >> 16;
				mData1 = (aMidiData & 0x0000FF00) >> 8;
				mData2 = (aMidiData & 0x00FF0000) >> 16;
				mStatus = aMidiData & 0x000000FF;
				OnMidiData = true;
				//mess = Buf, "\r\n", Buf2;
				//MessageBox (GetActiveWindow(), mess.c_str(), "Info", MB_OK|MB_ICONINFORMATION);
      }
		//MessageBox (GetActiveWindow(), "Midi Callback", "Info", MB_OK|MB_ICONINFORMATION|MB_TOPMOST);
  }

// ============================================================================
//
// CONDITIONS
// 
// ============================================================================

CONDITION(
	/* ID */			0,
	/* Name */			"%o: On MIDI Input",
	/* Flags */			EVFLAGS_ALWAYS,
	/* Params */		(0)
) {
    if (OnMidiData == 1)
      {
        /*rdPtrEx->*///OnMidiData = false;
        //MidiData->OnMidiData = false;
				//DoMidiInData (rdPtr->DeviceIndex, rdPtrEx->MidiStatus, rdPtrEx->MidiData1, rdPtrEx->MidiData2);
				OnMidiData = false;
        return true;
      }
    return false;
}

CONDITION(
	/* ID */			1,
	/* Name */			"",
	/* Flags */			EVFLAGS_ALWAYS|EVFLAGS_NOTABLE,
	/* Params */		(0)
) {
    return false;
}

CONDITION(
	/* ID */			2,
	/* Name */			"%o: On Error (Not Yet Ready)",
	/* Flags */			0,
	/* Params */		(0)
) {
    return false;
}
// ============================================================================
//
// ACTIONS
// 
// ============================================================================

ACTION(
	/* ID */			0,
    /* Name */			"Set MIDI In Device ID to: %0",
	/* Flags */			0,
    /* Params */		(1, PARAM_NUMBER, "Enter ID (0 based)")
) {
    rdPtr->DeviceID_in = Param (TYPE_INT);
}

ACTION(
	/* ID */			1,
    /* Name */			"Set MIDI Out Device ID to: %0",
	/* Flags */			0,
    /* Params */		(1, PARAM_NUMBER, "Enter ID (0 based)")
) {
    rdPtr->DeviceID_out = Param (TYPE_INT);
}

ACTION(
	/* ID */			2,
    /* Name */			"Open MIDI In Device",
	/* Flags */			0,
    /* Params */		(0)
) {
    unsigned long result, result2;
    //HMIDIIN      inHandle;
    result = midiInOpen (&(rdPtr->inHandle[rdPtr->DeviceID_in]), (UINT)rdPtr->DeviceID_in, reinterpret_cast<DWORD>(midiCallback), 0, CALLBACK_FUNCTION);
    if (result)
      MessageBox (GetActiveWindow(), "There was an error opening the specified MIDI In device!", "Error (midi.mfx)", MB_OK|MB_ICONERROR|MB_TOPMOST|MB_TASKMODAL);
    else
      {
        result2 = midiInStart (rdPtr->inHandle[rdPtr->DeviceID_in]);
        if (result2)
          MessageBox (GetActiveWindow(), "There was an error starting the specified MIDI In device!", "Error (midi.mfx)", MB_OK|MB_ICONERROR|MB_TOPMOST|MB_TASKMODAL);
      }
}

ACTION(
	/* ID */			3,
    /* Name */			"Open MIDI Out Device",
	/* Flags */			0,
    /* Params */		(0)
) {
    unsigned long result;
    //HMIDIOUT      outHandle;

    /* Open the default MIDI Out device */
    result = midiOutOpen (&rdPtr->outHandle[rdPtr->DeviceID_out], rdPtr->DeviceID_out, 0, 0, CALLBACK_NULL);
    if (result)
      {
        MessageBox (GetActiveWindow(), "There was an error opening the specified MIDI Out device!\r\nIt might be already Open?", "Error (midi.mfx)", MB_OK|MB_ICONERROR|MB_TOPMOST|MB_TASKMODAL);
      }
}

ACTION(
	/* ID */			4,
    /* Name */			"Play Last Note",
	/* Flags */			0,
    /* Params */		(0)
) {
	DoMidiInData  (rdPtr, mStatus, mData1, mData2);
}

ACTION(
	/* ID */			5,
    /* Name */			"Stop Listening",
	/* Flags */			0,
    /* Params */		(0)
) {

}

// ============================================================================
//
// EXPRESSIONS
// 
// ============================================================================

EXPRESSION(
	/* ID */			0,
	/* Name */			"NumMidiInDevices(",
	/* Flags */			0,
	/* Params */		(0)
) {
  return midiInGetNumDevs();
}

EXPRESSION(
	/* ID */			1,
	/* Name */			"NumMidiOutDevices(",
	/* Flags */			0,
	/* Params */		(0)
) {
  return midiOutGetNumDevs();
}

EXPRESSION(
	/* ID */			2,
	/* Name */			"MidiInDeviceName$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(1, EXPPARAM_NUMBER, "Device ID")
) {
    unsigned int num = ExParam(TYPE_INT);
    // Ensure the requested device number is within the range of known devices
    if (num > midiInGetNumDevs()) {
        ReturnStringSafe ("Out of Range");
    }

    MIDIINCAPS capabilities;

    if (midiInGetDevCaps(num, &capabilities, sizeof(MIDIINCAPS)) != MMSYSERR_NOERROR) {
        ReturnStringSafe ("Out of Range");
    }

    ReturnStringSafe (capabilities.szPname);
}

EXPRESSION(
	/* ID */			3,
	/* Name */			"MidiOutDeviceName$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(1, EXPPARAM_NUMBER, "Device ID")
) {
    unsigned int num = ExParam(TYPE_INT);
    // Ensure the requested device number is within the range of known devices
    if (num > midiOutGetNumDevs()) {
        ReturnStringSafe ("Out of Range");
    }

    MIDIOUTCAPS capabilities;

    if (midiOutGetDevCaps(num, &capabilities, sizeof(MIDIINCAPS)) != MMSYSERR_NOERROR) {
        ReturnStringSafe ("Out of Range");
    }

    ReturnStringSafe (capabilities.szPname);
}

EXPRESSION(
	/* ID */			4,
	/* Name */			"MidiNoteNum(",
	/* Flags */			0,
	/* Params */		(0)
) {
  return mData1;
}

EXPRESSION(
	/* ID */			5,
	/* Name */			"MidiNoteNumInOctave(",
	/* Flags */			0,
	/* Params */		(0)
) {
	int NoteNum = mData1;
	while (NoteNum >= 12)
		NoteNum -= 12;
	return NoteNum;
}

EXPRESSION(
	/* ID */			6,
	/* Name */			"MidiNoteName$(",
	/* Flags */			EXPFLAG_STRING,
	/* Params */		(0)
) {
	int NoteNum = mData1;
	while (NoteNum >= 12)
		NoteNum -= 12;
	ReturnStringSafe (Note[NoteNum].c_str());
}

EXPRESSION(
	/* ID */			7,
	/* Name */			"DISABLED(",
	/* Flags */			0,
	/* Params */		(0)
) {
  return 0;
}

EXPRESSION(
	/* ID */			8,
	/* Name */			"MidiRawData1(",
	/* Flags */			0,
	/* Params */		(0)
) {
  return mData1;
}

EXPRESSION(
	/* ID */			9,
	/* Name */			"MidiRawData2(",
	/* Flags */			0,
	/* Params */		(0)
) {
	return mData2;
}

EXPRESSION(
	/* ID */			10,
	/* Name */			"MidiRawStatus(",
	/* Flags */			0,
	/* Params */		(0)
) {
	return mStatus;
}
