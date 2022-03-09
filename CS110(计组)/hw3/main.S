# DO NOT REMOVE THIS LINE WHEN SUBMITTING
.import input.S

.text  # code starts here

.globl main
main:
    
    li s1 0 #s1=result
    la a2 str1
    la a3 str2
    lw a4 len1#m
    lw a5 len2#n
    beq a4,x0,PrintResult
    beq a5,x0,PrintResult
    # jal func
    addi t1,x0,0 #int i=0
    SJDIWJWE:
            addi sp,sp,-4
            sw t1,0(sp)
            addi a0,t1,0
            jal searchForOne
            lw t1,0(sp)
            addi sp,sp,4
        bge s1,a0,DONSODIWOQ
        mv s1 a0
        DONSODIWOQ:
        addi t1,t1,1
        bne t1,a4,SJDIWJWE
    
    PrintResult:
    li a0,1
    mv a1,s1
    ecall
    li a0 10
    ecall

searchForOne:
# need one arg called s(a0)
    #####save reg#####
    addi sp,sp,-8
    sw t5,0(sp)
    sw ra,4(sp)
    #####save reg#####
    
    mv s3 a0 # s3=s ;
    li s4 0 # int result = 0;
        mv a0 a2 
        mv a1 s3
        jal loadStringChar
    #a0 = str1[s]
    mv s7 a0 # char finder=str1[s] ;
    li t1,0#t1=i
    forasdwqewq:
            mv a0 a3 
            mv a1 t1
            jal loadStringChar
            #a0 = str2[i]
        mv t4 a0
        bne t4 s7 ifaijewjeioq

        # result = max(matchString(s, i), result);
            addi sp,sp,-4
            sw s7,0(sp)
            mv a0 s3
            mv a1 t1
        jal matchString
        lw s7,0(sp)
        addi sp,sp,4

            mv a1 s4
        jal max
        mv s4 a0

    ifaijewjeioq:
        addi t1,t1,1
        blt t1 a5 forasdwqewq
    mv a0 s4
    #####restore reg#####
    lw t5,0(sp)
    lw ra,4(sp)
    addi sp,sp,8
    #####restore reg#####
    jr ra

matchString:
#a0 =s a1=t
# use s3-s9
    #####save reg#####
    addi sp,sp,-20
    sw ra,0(sp)
    sw t1,4(sp)
    sw s3,8(sp)
    sw s7,12(sp)
    sw t4,16(sp)
    #####save reg#####
    mv s8 a0 #s=s8
    mv s9 a1 #t = s9

    li s3 1 # int result = 1;
    # int largestRe = min(m - s - 1, n - t - 1);
        mv a0 a4
        sub a0 a0 s8
        addi a0,a0,-1
        mv a1 a5
        sub a1 a1 s9
        addi a1,a1,-1
    jal min
    beq a0,x0,ajwijeqjejiqwo
    mv s7 a0 #s7==largestRe
    # int i=1;
    li s5 1
    ahwqkljelqw:
    # c1=str1[s + i];
    # c2= str2[t + i];
        mv a0 a2 
        mv a1 s8
        add a1,a1,s5
    jal loadStringChar
    mv t3,a0 #c1=str1[s + i];

        mv a0 a3 
        mv a1 s9
        add a1,a1,s5
    jal loadStringChar
    mv t4,a0 #c2= str2[t + i];
    bne t3,t4,ajwijeqjejiqwo
    addi s3,s3,1
    addi s5,s5,1

    bge s7,s5,ahwqkljelqw
    ajwijeqjejiqwo:
    mv a0 s3



    #####restore reg#####
    lw t4,16(sp)
    lw s7,12(sp)
    lw s3,8(sp)
    lw t1,4(sp)
    lw ra,0(sp)
    addi sp,sp,20
    #####restore reg#####
    jr ra

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