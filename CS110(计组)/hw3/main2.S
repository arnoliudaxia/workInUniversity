# DO NOT REMOVE THIS LINE WHEN SUBMITTING
.import input.S

.text  # code starts here

.globl main
main:
    
    la s7 str1
    la s8 str2
    lw a4 len1#m
    lw a5 len2#n
    li s1 0 #s1=result
    beq a4,x0,PrintResult
    beq a5,x0,PrintResult

    # int* s4 = (int*)calloc(a4 + 1, sizeof(int));
        li a0 9
        mv t1 a4
        addi t1 t1 1
        slli t1 t1 2
        mv a1 t1
        ecall
        mv s4 a0
    # int* s5 = (int*)calloc(a5 + 1, sizeof(int));
        li a0 9
        mv t1 a5
        addi t1 t1 1
        slli t1 t1 2
        mv a1 t1
        ecall
        mv s5 a0
        li a1 0
        li a2 0
        jal ListChange#s5[0]=0

    li s9 1
    WJOIJE:
        li s10 1
            
            mv a0 s7
            mv a1 s9
            addi a1 a1 -1
            jal loadStringChar
            mv t2 a0
    SHDIOWHOI:


            mv a0 s8
            mv a1 s10
            addi a1 a1 -1
        jal loadStringChar
        mv t3 a0
        bne t2 t3 SJDIOW
        
        # s5[s10] = s4[s10 - 1] + 1;
            # first get s4[s10-1]
            mv a0 s4
            mv a1 s10
            addi a1 a1 -1
            jal loadStringChar
            mv t2 a0# now t2=s4[s10-1]

            mv a0 s5
            mv a1 s10
            mv a2 t2
            addi a2 a2 1
            jal ListChange
            
        # s1 = max(s5[s10](t2), s1);
            mv a0 a2
            mv a1 s1
            jal max
            mv s1 a0

        SJDIOW:
        addi s10 s10 1
        mv t1 a5
        addi t1 t1 1
        blt s10 t1 SHDIOWHOI
        li s10 0
    SJIWJIO:
        # s4[s10] = s5[s10];
            mv a0 s5
            mv a1 s10
            jal loadStringChar
            mv t3 a0#t3 is s5[s10]

            mv a0 s4
            mv a1 s10
            mv a2 t3
            jal ListChange
        # s5[s10] = 0;
            mv a0 s5
            mv a1 s10
            li a2 0
            jal ListChange
        addi s10 s10 1
        mv t1 a5
        addi t1 t1 1
        blt s10 t1 SJIWJIO

    addi s9 s9 1
    mv t1 a4
    addi t1 t1 1
    blt s9 t1 WJOIJE

    PrintResult:
    li a0,1
    mv a1,s1
    ecall
    li a0 10
    ecall

LOPSP:

loadStringChar:
#give the string a0,return the char of a1 position into a0
#the caller must save t1
# no need now, i save it
    #####save reg#####
    addi sp,sp,-4
    sw t1,0(sp)
    #####save reg#####

    slli a1 a1 2
    add a0 a0 a1
    lw a0 0(a0)
    #####restore reg#####
    lw t1,0(sp)
    addi sp,sp,4
    #####restore reg#####
    jr ra

ListChange:
# a0 is the address, a1 is the index, a2 is the replacing number
#the caller must save t1
    li t1 -1
    addi a0,a0,-4

    admoqin:
    addi t1,t1,1
    addi a0,a0,4
    beq t1 a1 asndoiqwb
    j admoqin

    asndoiqwb:
    sw a2 0(a0)

    jr ra

max:
    # compare a0 and a1, return the bigger one into a0
    bge a0,a1,ReturMax 
    addi a0,a1,0
    ReturMax:
    jr ra
min:
    # compare a0 and a1, return the samller one into a0
    bge a1,a0,ReturMin 
    addi a0,a1,0
    ReturMin:
    jr ra

#final is something
#i'd like to say
#about the project
#First i write a 
#c type version to finish this
#task#final is something
#i'd like to say
#about the project
#First i write a 
#c type version to finish this
#task#final is something
#i'd like to say
#about the project
#First i write a #final is something
#i'd like to say
#about the project
#First i write a 
#c type version to finish this
#task#final is something
#i'd like to say
#about the project
#First i write a 
#c type version to finish this
#task#final is something
#i'd like to say
#about the project#i'd like to say
#about the project
#First i write a 
#c type version to finish this
#task#final is something
#i'd like to say
#about the project
#First i write a 
#c type version to finish this
#task#final is something
#i'd like to say
#about the project#i'd like to say
#about the project
#First i write a 
#c type version to finish this
#task#final is something
#i'd like to say
#about the project
#First i write a 
#c type version to finish this
#task#final is something
#i'd like to say
#about the project
#First i write a 
#c type version to finish this
#task#final is something
#i'd like to say
#about the project
#First i write a 
#c type version to finish this
#task#final is something
#i'd like to say
#about the project
#First i write a 
#c type version to finish this
#task#final is something
#i'd like to say
#about the project
#First i write a 
#c type version to finish this
#task#final is something
#i'd like to say
#about the project
#First i write a 
#c type version to finish this
#task#final is something
#i'd like to say
#about the project
#First i write a 
#c type version to finish this
#task