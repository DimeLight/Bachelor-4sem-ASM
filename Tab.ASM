format MZ
org 100h
include 'Macrosbi.inc'

main:

       finit
       fldz
       fst [a]
       fst [b]
       fst [detx]
       fstp [y]

prent GlavUved
prent aravn
chitaem a
prent detxravn
chitaem detx
prent bravn
chitaem b

        finit

        fld1
        fld [a]
        fcomip st1
      jnb odz1
        prent aerrg
        jmp main

      odz1:

        finit
        mov [buff],0
        fstcw [buff]
        and [buff], 1111001111111111b
        or [buff], 1111011111111111b
        fldcw [buff]
        fld [b]
        fsub [a]

        fldz
        fxch
        fcomi st1
        faddp
      jnb odz2
        prent ierrg
        jmp main

      odz2:

        fdiv [detx]
        FRNDINT
        fist dword [buff]
        mov ecx,dword [buff]

prent subtabUved
prent palochki


tab:
        prentx a

        finit
        fild [four]
        fldln2
        fld [a]
        fyl2x
        fmulp
        fld [a]
        fdivrp
        fsqrt
        fstp [y]
        prentx y

      jmp aoao
          tab1: jmp tab
      aoao:

        prent palochki

        finit
        fld [a]
        fld [detx]
        fadd st0,st1
        fst [a]
        fld [b]
      loop tab1

endinghell:
        getouthere



four dq 4
a rq 1
b rq 1
detx rq 1
y rq 1
buff rw 1
dodot rw 1
aftdot rw 1
GlavUved: db "Programma tabulyacii funkcii sqrt(x/(4ln(x)))",0Ah,"vvod - 7 simvolov (pyatii - .)",0Ah,"primer: 0034.56",0Ah,"vvodit` chisla bez Enter",0Ah,"ODZ x>1",0Ah,"$"
subtabUved: db "Vyvod tabulyacii v vide:",0Ah,"x",0Ah,"y",0Ah,"$"
palochki: db 10 dup "-",0Ah,"$"
aerrg: db 0Ah,"a ne udovletvoryaet ODZ, vvedite vse zanovo",0Ah,0Ah,"$"
ierrg: db 0Ah,"interval otricatelnii ili = 0, vvedite vse zanovo",0Ah,0Ah,"$"
aravn: db "Nachalo intervala tabulirovaniya a = ",0Ah,"$"
detxravn: db "SHag tabulirovaniya detx = ",0Ah,"$"
bravn: db "Konec intervala tabulirovaniya b = ",0Ah,"$"