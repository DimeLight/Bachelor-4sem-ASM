macro getouthere
     {
        mov eax,4C00h
        int 21h
     }

macro prent streng
     {
        mov edx,streng
        mov eax,0900h
        int 21h
     }

macro prentOx polovina,del
     {

        xor eax,eax
        xor edx,edx
        xor ebx,ebx

        mov ax,[polovina]
        mov bx,del
        div bx
        mov [polovina],dx

        xor edx,edx
        add al,'0'
        mov dl,al

        mov ah,06h
        int 21h

     }

macro prentx valux
     {

local jgood,negood,good2,jgood2,negood2,neggood,good

        finit
        fld1
        fld [valux]
        fprem
        mov [buff],100
        fild [buff]
        fmul st0,st1
        frndint
        fist [aftdot]

        cmp [aftdot],0
        jge jgood2
        jmp negood2

      jgood2:
      jmp good2

      negood2:

        neg [aftdot]

      good2:

        finit
        fld [valux]

        mov [buff],0
        fstcw [buff]
        and [buff], 1111001111111111b
        or [buff], 1111011111111111b
        fldcw [buff]

        frndint
        fist [dodot]

        cmp [dodot],0
        jge jgood
        jmp negood

      jgood:
      jmp good

      negood:

        xor edx,edx
        add dx,'-'
        mov ah,06h
        int 21h
        cmp [aftdot],0
        je neggood
        add [dodot],1
      neggood:
        neg [dodot]
      good:

        prentOx dodot, 1000
        prentOx dodot, 100
        prentOx dodot, 10
        prentOx dodot, 1

        xor edx,edx
        add dx,'.'
        mov ah,06h
        int 21h

        prentOx aftdot, 10
        prentOx aftdot, 1
        xor edx,edx

        mov dl,0Ah
        mov ah,06h
        int 21h
     }

macro chitaemOx
     {
        xor eax,eax
        mov ah,01h
        int 21h
     }

macro domnoghaemOx mod,Oxe
     {
        xor ah,ah
        sub ax,'0'
        mov [buff],ax

        finit
        fild [buff]
        mov [buff],mod
        fild [buff]
        fmul st0,st1
        fst [Oxe]
     }

macro delimOx mod,Oxe
     {
        xor ah,ah
        sub ax,'0'
        mov [buff],ax

        finit
        fild [buff]
        mov [buff],mod
        fild [buff]
        fdiv st1,st0
        fld [Oxe]
        fadd st0,st2
        fst [Oxe]
     }

macro chitaem valuxe
     {

        chitaemOx
        domnoghaemOx 1000,valuxe

        chitaemOx
        domnoghaemOx 100,valuxe

        chitaemOx
        domnoghaemOx 10,valuxe

        chitaemOx
        domnoghaemOx 1,valuxe

        chitaemOx

        chitaemOx
        delimOx 10,valuxe

        chitaemOx
        delimOx 100,valuxe

        xor edx,edx
        mov dl,0Ah
        mov ah,06h
        int 21h
     }
