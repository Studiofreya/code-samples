; Listing generated by Microsoft (R) Optimizing Compiler Version 16.00.40219.01 

	TITLE	P:\cpp\circular-templates\circular-templates.cpp
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB LIBCMT
INCLUDELIB OLDNAMES

PUBLIC	?MsgId@?$Message@N@@2HB				; Message<double>::MsgId
;	COMDAT ?MsgId@?$Message@N@@2HB
CONST	SEGMENT
?MsgId@?$Message@N@@2HB DD 00H				; Message<double>::MsgId
CONST	ENDS
PUBLIC	??$setComponentHandler@V?$Message@N@@@Entity@@QAEXAAVComponent@@@Z ; Entity::setComponentHandler<Message<double> >
PUBLIC	_main
; Function compile flags: /Odtp
_TEXT	SEGMENT
_e$ = -2						; size = 1
_c$ = -1						; size = 1
_main	PROC
; File p:\cpp\circular-templates\circular-templates.cpp
; Line 85
	push	ebp
	mov	ebp, esp
	push	ecx
; Line 89
	lea	eax, DWORD PTR _c$[ebp]
	push	eax
	lea	ecx, DWORD PTR _e$[ebp]
	call	??$setComponentHandler@V?$Message@N@@@Entity@@QAEXAAVComponent@@@Z ; Entity::setComponentHandler<Message<double> >
; Line 91
	xor	eax, eax
; Line 92
	mov	esp, ebp
	pop	ebp
	ret	0
_main	ENDP
_TEXT	ENDS
PUBLIC	??$setHandler@V?$Message@N@@V<lambda0>@?A0x164df54e@@@MessageHandler@@QAEXABV<lambda0>@?A0x164df54e@@@Z ; MessageHandler::setHandler<Message<double>,`anonymous namespace'::<lambda0> >
; Function compile flags: /Odtp
;	COMDAT ??$setComponentHandler@V?$Message@N@@@Entity@@QAEXAAVComponent@@@Z
_TEXT	SEGMENT
_this$ = -8						; size = 4
$T2641 = -2						; size = 1
_handleMsg$ = -1					; size = 1
_component$ = 8						; size = 4
??$setComponentHandler@V?$Message@N@@@Entity@@QAEXAAVComponent@@@Z PROC ; Entity::setComponentHandler<Message<double> >, COMDAT
; _this$ = ecx
; Line 71
	push	ebp
	mov	ebp, esp
	sub	esp, 8
	mov	DWORD PTR _this$[ebp], ecx
; Line 73
	xor	eax, eax
	mov	BYTE PTR $T2641[ebp], al
; Line 77
	lea	ecx, DWORD PTR _handleMsg$[ebp]
	push	ecx
	mov	ecx, DWORD PTR _component$[ebp]
	call	??$setHandler@V?$Message@N@@V<lambda0>@?A0x164df54e@@@MessageHandler@@QAEXABV<lambda0>@?A0x164df54e@@@Z ; MessageHandler::setHandler<Message<double>,`anonymous namespace'::<lambda0> >
; Line 78
	mov	esp, ebp
	pop	ebp
	ret	4
??$setComponentHandler@V?$Message@N@@@Entity@@QAEXAAVComponent@@@Z ENDP ; Entity::setComponentHandler<Message<double> >
; Function compile flags: /Odtp
_TEXT	ENDS
;	COMDAT ??$setHandler@V?$Message@N@@V<lambda0>@?A0x164df54e@@@MessageHandler@@QAEXABV<lambda0>@?A0x164df54e@@@Z
_TEXT	SEGMENT
_this$ = -8						; size = 4
_id$ = -4						; size = 4
_msghandler$ = 8					; size = 4
??$setHandler@V?$Message@N@@V<lambda0>@?A0x164df54e@@@MessageHandler@@QAEXABV<lambda0>@?A0x164df54e@@@Z PROC ; MessageHandler::setHandler<Message<double>,`anonymous namespace'::<lambda0> >, COMDAT
; _this$ = ecx
; Line 32
	push	ebp
	mov	ebp, esp
	sub	esp, 8
	mov	DWORD PTR _this$[ebp], ecx
; Line 34
	mov	DWORD PTR _id$[ebp], 0
; Line 35
	mov	esp, ebp
	pop	ebp
	ret	4
??$setHandler@V?$Message@N@@V<lambda0>@?A0x164df54e@@@MessageHandler@@QAEXABV<lambda0>@?A0x164df54e@@@Z ENDP ; MessageHandler::setHandler<Message<double>,`anonymous namespace'::<lambda0> >
_TEXT	ENDS
END
