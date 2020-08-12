;|----------------------------Specifications-----------------------------------
;|This program searches for "termToSearchFor" in "arrayToSearch" and says
;|whether or not the element is in the array.
;|
;|Works in Windows 10 and probably older versions too
;|-----------------------------------------------------------------------------
;
;|------------------------------Compilation------------------------------------
;|You need MASM to compile this. The command to compile is:
;|		ml LinearSearch.asm /link /subsystem:windows /defaultlib:kernel32.lib
;|					/defaultlib:user32.lib /libpath:"path_to_Windows_SDK"
;|
;|Just replace the libpath with the path to the windows sdk where kernel32.lib
;|and user32.lib are located
;|-----------------------------------------------------------------------------


.386
.model FLAT, STDCALL
.stack 4096
OPTION casemap:none
ExitProcess PROTO,dwExitCode:DWORD
MessageBoxA PROTO,										;This stuff allows you to display a MessageBox
		hWnd:DWORD,
		lpText:PTR BYTE,
		lpCaption:PTR BYTE,
		uTYPE:DWORD

INCLUDELIB kernel32.lib									;Needed for MessageBoxA
INCLUDELIB user32.lib									;Needed for ExitProcess

.data
arrayToSearch SBYTE 12, 20, 37, 52, 39, 5, 32				;This array can be changed as desired. The #'s can be negative too
termToSearchFor SBYTE 20
foundString BYTE "The element is in the array.", 0
nopeString BYTE "Nope.", 0
titleString BYTE "Linear Search", 0

.code
main PROC
	MOV eax, OFFSET arrayToSearch
	MOV ecx, LENGTHOF arrayToSearch
	MOV bl, termToSearchFor

L1:													;Loop that searches through the array
	CMP bl, BYTE PTR [eax]
	JE found
	INC eax
	LOOP L1
	JMP nope

found:
	INVOKE MessageBoxA, 0, OFFSET foundString, OFFSET titleString, 0
	JMP stop

nope:
	INVOKE MessageBoxA, 0, OFFSET nopeString, OFFSET titleString, 0

stop:
	INVOKE ExitProcess, 0

main ENDP
END main