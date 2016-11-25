// --------------------------------
// Condition menu
// --------------------------------

#ifdef CONDITION_MENU

	ITEM (0, "On MIDI Input")
  //ITEM (1, "On Note Up")
  SEPARATOR
  DISABLED (2, "On Error")

#endif

// --------------------------------
// Action menu
// --------------------------------

#ifdef ACTION_MENU

	ITEM (0, "Set MIDI In Device (ID)")
  ITEM (1, "Set MIDI Out Device (ID)")
  SEPARATOR
  ITEM (2, "Open MIDI In Device")
  ITEM (3, "Open MIDI Out Device")
	SEPARATOR
  ITEM (4, "Play Last Note")
  SEPARATOR

#endif


// --------------------------------
// Expression menu
// --------------------------------

#ifdef EXPRESSION_MENU

	ITEM (0, "Get Number of MIDI In Devices")
  ITEM (1, "Get Number of MIDI Out Devices")
  ITEM (2, "Get Name of Specific MIDI In Device")
  ITEM (3, "Get Name of Specific MIDI Out Device")
  SEPARATOR
  SUB_START ("Get Note")
    ITEM (4, "Actual Number")
		ITEM (5, "Number in Octave")
    ITEM (6, "Name")
    DISABLED (7, "Octave")
    SEPARATOR
    ITEM (8, "Raw Data 1")
    ITEM (9, "Raw Data 2")
		ITEM (10, "Raw Status")
  SUB_END
  SEPARATOR

#endif