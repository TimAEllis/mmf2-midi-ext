class rRundata;
typedef rRundata * LPRRDATA;

// --------------------------------
// RUNNING OBJECT DATA STRUCTURE
// --------------------------------
// If you want to store anything between actions/conditions/expressions
// you should store it here

typedef struct tagRDATA
{
	#include  "MagicRDATA.h"
		int       DeviceID_in;
    int       DeviceID_out;
    HMIDIIN   inHandle [99];
    HMIDIOUT  outHandle [99];
    bool      OnMidiData;
    bool      OutputMIDI;
    int       DeviceIndex;
    int       MidiStatus;
    int       MidiData1;
    int       MidiData2;

} RUNDATA;
typedef	RUNDATA	* LPRDATA;

//typedef struct
//  {
//    int MidiStatus;
//    int MidiData1;
//    int MidiData2;
//		bool OnMidiData;
//  } TMidi;

// --------------------------------
// EDITION OF OBJECT DATA STRUCTURE
// --------------------------------
// These values let you store data in your extension that will be saved in the MFA
// You should use these with properties

typedef struct tagEDATA_V1
{
	extHeader		eHeader;
//	short			swidth;
//	short			sheight;

} EDITDATA;
typedef EDITDATA * LPEDATA;
