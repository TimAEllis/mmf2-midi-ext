#include "EventIDs.h"
// --------------------------------
// Condition menu
// --------------------------------

#ifdef CONDITION_MENU

	DISABLED(DISABLED_ID, "Version: 1.0")
	SEPARATOR
	ITEM(CONDITION_ID_ON_INPUT, "On MIDI Input")
	ITEM(CONDITION_ID_ON_IN_DEVICE_ENUM, "On MIDI In Device Enumerated")
	ITEM(CONDITION_ID_ON_OUT_DEVICE_ENUM, "On MIDI Out Device Enumerated")
	SEPARATOR
	ITEM(CONDITION_ID_ON_ERROR, "On Error")
	SEPARATOR

#endif

// --------------------------------
// Action menu
// --------------------------------

#ifdef ACTION_MENU

	DISABLED(DISABLED_ID, "Version: 1.0")
	SEPARATOR
	ITEM(ACTION_ID_SET_MIDI_IN_DEVICE, "Set MIDI In device (ID)")
	ITEM(ACTION_ID_SET_MIDI_OUT_DEVICE, "Set MIDI Out device (ID)")
	SEPARATOR
	SUB_START("MIDI In")
		ITEM(ACTION_ID_OPEN_MIDI_IN_DEVICE, "Open MIDI In device")
		ITEM(ACTION_ID_CLOSE_MIDI_IN_DEVICE, "Close MIDI In device")
		SEPARATOR
		ITEM(ACTION_ID_ENUM_MIDI_IN_DEVICES, "Enumerate MIDI In devices")
	SUB_END
	SUB_START("MIDI Out")
		ITEM(ACTION_ID_OPEN_MIDI_OUT_DEVICE, "Open MIDI Out device")
		ITEM(ACTION_ID_CLOSE_MIDI_OUT_DEVICE, "Close MIDI Out device")
		SEPARATOR
		ITEM(ACTION_ID_ENUM_MIDI_OUT_DEVICES, "Enumerate MIDI Out devices")
	SUB_END
	SEPARATOR
	ITEM(ACTION_ID_PLAY_LAST_NOTE, "Play last note")
	ITEM(ACTION_ID_SEND_MSG_TO_OUT_DEV, "Send MIDI message to current MIDI Out device")
	SEPARATOR

#endif


// --------------------------------
// Expression menu
// --------------------------------

#ifdef EXPRESSION_MENU

	DISABLED(DISABLED_ID, "Version: 1.0")
	SEPARATOR
	ITEM(EXPRESSION_ID_GET_NUM_IN_DEVICES, "Get number of MIDI In devices")
	ITEM(EXPRESSION_ID_GET_NUM_OUT_DEVICES, "Get number of MIDI Out devices")
	ITEM(EXPRESSION_ID_GET_NAME_IN_DEVICE, "Get name of specific MIDI In device")
	ITEM(EXPRESSION_ID_GET_NAME_OUT_DEVICE, "Get name of specific MIDI Out device")
	SEPARATOR
	SUB_START("Get note")
		ITEM(EXPRESSION_ID_GET_NOTE_ACTUAL_NOTE, "Actual number")
		ITEM(EXPRESSION_ID_GET_NOTE_NUM_IN_OCTAVE, "Number in octave")
		ITEM(EXPRESSION_ID_GET_NOTE_NAME, "Name")
		ITEM(EXPRESSION_ID_GET_NOTE_OCTAVE_NUM, "Octave number")
		SEPARATOR
		ITEM(EXPRESSION_ID_GET_NOTE_RAW_DATA_ONE, "Raw Data 1")
		ITEM(EXPRESSION_ID_GET_NOTE_RAW_DATA_TWO, "Raw Data 2")
		ITEM(EXPRESSION_ID_GET_NOTE_RAW_STATUS, "Raw Status")
	SUB_END
	SUB_START("Enumerated")
		SUB_START("MIDI In")
			ITEM(EXPRESSION_ID_ENUM_IN_NAME, "Device name")
			ITEM(EXPRESSION_ID_ENUM_IN_INDEX, "Device index")
		SUB_END
		SUB_START("MIDI Out")
			ITEM(EXPRESSION_ID_ENUM_OUT_NAME, "Device name")
			ITEM(EXPRESSION_ID_ENUM_OUT_INDEX, "Device index")
		SUB_END
		SUB_END
	SUB_START("On error")
		ITEM(EXPRESSION_ID_ON_ERROR_GET_TYPE, "Get error type")
		ITEM(EXPRESSION_ID_ON_ERROR_GET_DESC, "Get error description")
	SUB_END
	SEPARATOR

#endif