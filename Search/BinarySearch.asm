;|----------------------------Specifications-----------------------------------
;|Uses the binary search algorithm to return the index of the element in the
;|array. If the element is not in the array it returns "The element could not
;|be found".
;|
;|Works in Windows 10 and probably older versions too
;|-----------------------------------------------------------------------------
;
;|------------------------------Compilation------------------------------------
;|You need MASM to compile this. The command to compile is:
;|		ml BinearySearch.asm /link /subsystem:windows /defaultlib:kernel32.lib
;|					/defaultlib:user32.lib /libpath:"path_to_Windows_SDK"
;|
;|Just replace the libpath with the path to the Windows sdk where kernel32.lib
;|and user32.lib are located
;|-----------------------------------------------------------------------------

.model FLAT, STDCALL
.stack 4096
OPTION casemap:none
ExitProcess PROTO,dwExitCode:DWORD
MessageBoxA PROTO,
		hWnd:DWORD,
		lpText:PTR BYTE,
		lpCaption:PTR BYTE,
		uTYPE:DWORD

INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
arrayToSearch SBYTE 1, 7, 10, 20, 21, 26, 28, 31, 34, 35, 50, 55, 80	;These numbers can be in the range -128 to 127
termToSearchFor SBYTE 31
divisor BYTE 2
L SBYTE 0																;Left bound
R SBYTE LENGTHOF arrayToSearch											;Right bound
M BYTE 0																;The middle of the section being checked
failString BYTE "The element could not be found", 0
titleString BYTE "Binary Search", 0
indexString BYTE 3 dup(48), 0
indexStringDivisor BYTE 10												;Used to turn an integer into a string

.code
main PROC
	sub R, 1
	mov bl, L
	mov bh, R

mainLoop:
	cmp bl, bh
	jg fail
	movsx ax, bl
	movsx dx, bh
	add ax, dx
	div divisor
	mov M, al
	mov edx, OFFSET arrayToSearch
	movzx ecx, M
	add edx, ecx
	mov ah, termToSearchFor
	mov al, [edx]
	cmp al, ah
	jl lessThan
	jg greaterThan
	call intToString

lessThan:
	mov dh, M
	inc dh
	mov bl, dh						;setting L to M + 1
	jmp mainLoop

greaterThan:
	mov dh, M
	dec dh
	mov bh, dh						;setting R to M - 1
	jmp mainLoop	

fail:
	INVOKE MessageBoxA, 0, OFFSET failString, OFFSET titleString, 0
	INVOKE ExitProcess, 0

main ENDP

;-------------------------------------------------------------
;	Translates the integer 'M' into a String at 'indexString'
;-------------------------------------------------------------
intToString PROC
	mov ecx, 3
	mov dl, M
L1:									;This loop translates an int up to 3
	dec ecx							;digits to a string
	mov ebx, OFFSET indexString
	add ebx, ecx
	movzx ax, dl
	div indexStringDivisor
	mov dl, al						;Quotient to dl
	mov dh, ah						;Remainder to dh
	add [ebx], dh
	cmp dl, dh						;Check if the remainder is greater than the quotient
	jg L1

	dec ecx
	mov ebx, OFFSET indexString
	add ebx, ecx
	add [ebx], dl
	INVOKE MessageBoxA, 0, OFFSET indexString, OFFSET titleString, 0
	INVOKE ExitProcess, 0
intToString ENDP

END main
	