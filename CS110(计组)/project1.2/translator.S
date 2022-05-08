#   Project 1.2 RVC instructions to RISC-V instructions in RISC-V

#   You can suppose you will get the number of machine codes you should translate from 
#   "lines_of_rvc_codes" and get the 16 or 32 bits-machine codes from "rvc_codes". 
#   Both of them are stored in file "input.S"

#   When we test your project, we will change the input files content.
#   Project 1.2 RVC instructions to RISC-V instructions in RISC-V

.import input.S

# Your code to convert the RVC codes to RVI codes.
la s8 lines_of_rvc_codes
lw s8 0(s8)
li s7 0
la s6 rvc_codes
#申请放所有指令的内存空间
li a0 9
li t0 32
mul a1 s8 t0
ecall
#申请放所有指令的内存空间
#but this 
#is the code
# 16 or 32 bytes content 
mv s9 a0
li a0 9
li t0 32
mul a1 s8 t0
ecall
mv a7 a0
mv a6 a7



loop:
#the main loop
# traael all lines of code
    beq s7 s8 fixaddress
    lw s11 0(s6)
    li s10 0
    li s2 0b11
    andi s3 s11 0b11 
    bne s3 s2 judge
    addi s7 s7 1
    addi s6 s6 4
    jal main
    j loop
judge:
    li s10 1
    lh s11 0(s6)
    addi s6 s6 2
    addi s7 s7 1
    jal main
    j loop
    
exit:
    li s9 0x10008000
    li t5 0
    PRINTALLL:
    beq t5 s8 ENDALLRPO
    lw a2 0(s9)
    jal print32
    addi t5 t5 1
    addi s9 s9 4
    j PRINTALLL
    ENDALLRPO:
    add	   a1, x0, x0
    addi   a0, x0, 17
    ecall
# Exit with error code 0
main:
    addi sp sp -4
    sw ra 0(sp)
li t0 1
bne s10 t0 saveInarrayS9
Phrase:
    #############save all opcode and funct#############
    # in order to save
    # simplify our code and
    # we decide to starct the opcode and
    # functs 
    # at the very first place
    li t6 0b1110000000000000
    and t0 s11 t6
    srli t0 t0 13
    li t6 0b1111000000000000
    and t1 s11 t6
    srli t1 t1 12
    li t6 0b1111110000000000
    and t2 s11 t6
    srli t2 t2 10 
    li t6 0b110000000000
    and t3 s11 t6
    srli t3 t3 10
    li t6 0b1100000
    and t4 s11 t6
    srli t4 t4 5
    andi t5 s11 0b11
    li t6 0b1111100
    and t6 s11 t6
    srli t6 t6 2
    ################################################
#now we simply 
#judge each type of code 
ADD: 
    li s1 0b1001
    li s2 0b10
    li s3 0
    #the method is quite simple
    #isjdit not meets the constrains
    #just jump to next possible
    #code type
    bne s1 t1 MV
    bne s2 t5 MV
    beq s3 t6 MV
    li s4 0b00000000000000000000000000110011
    li s5 0b111110000000
    and s5 s11 s5
    add s4 s4 s5
    slli s5 s5 8
    add s4 s4 s5
    li s5 0b1111100
    and s5 s11 s5
    slli s5 s5 18
    add s4 s4 s5
    mv s11 s4
    j saveInarrayS9

MV:
#all is the same 
#as above
    li s1 0b1000
    li s2 0b10
    li s3 0
    bne s1 t1 JR
    bne s2 t5 JR
    beq s3 t6 JR
    li s4 0b00000000000000000000000000110011
    li s5 0b111110000000
    and s5 s11 s5
    add s4 s4 s5
    li s5 0b1111100
    and s5 s11 s5
    slli s5 s5 18
    add s4 s4 s5
    mv s11 s4
    j saveInarrayS9


JR:
#all is the same 
#as above
    li s1 0b1000
    li s2 0b10
    li s3 0
    bne s1 t1 JALR
    bne s2 t5 JALR
    bne s3 t6 JALR
    li s4 0b00000000000000000000000001100111
    li s5 0b111110000000
    and s5 s11 s5
    slli s5 s5 8
    add s4 s4 s5
    mv s11 s4
    j saveInarrayS9

JALR:
#all is the same 
#as above
    li s1 0b1001
    li s2 0b10
    li s3 0
    bne s1 t1 LI
    bne s2 t5 LI
    bne s3 t6 LI
    li s4 0b00000000000000000000000001100111
    li s5 0b111110000000
    and s5 s11 s5
    slli s5 s5 8
    add s4 s4 s5
    li s1 0b10000000
    add s4 s4 s1
    mv s11 s4
    j saveInarrayS9
    
LI:
#all is the same 
#as above
    li s1 0b010
    li s2 0b01
    bne s1 t0 LUI
    bne s2 t5 LUI
    li s3 0b00000000000000000000000000010011
    li s4 0b1000000000000
    and s4 s4 s11
    li s5 0b1000000000000
    beq s4 s5 expand1
    back1:
    slli s4 s4 13
    add s3 s3 s4 
    li s4 0b111110000000
    and s4 s4 s11
    add s3 s3 s4
    li s4 0b1111100
    and s4 s4 s11
    slli s4 s4 18
    add s3 s3 s4
    mv s11 s3
    j saveInarrayS9

LUI:
    #all is the same 
    #as above
    li s1 0b011
    li s2 0b01
    bne s1 t0 ADDI
    bne s2 t5 ADDI
    li s3 0b00000000000000000000000000110111
    li s4 0b1000000000000
    and s4 s4 s11
    li s5 0b1000000000000
    beq s4 s5 expand2
    back2:
    slli s4 s4 5
    add s3 s3 s4 
    li s4 0b111110000000
    and s4 s4 s11
    add s3 s3 s4
    li s4 0b1111100
    and s4 s4 s11
    slli s4 s4 10
    add s3 s3 s4
    mv s11 s3
    j saveInarrayS9

ADDI:
    #all is the same 
    #as above
    li s1 0b000
    li s2 0b01
    bne s1 t0 SLLI
    bne s2 t5 SLLI
    li s3 0b00000000000000000000000000010011
    li s4 0b1000000000000
    and s4 s4 s11
    li s5 0b1000000000000
    beq s4 s5 expand3
    back3:
    slli s4 s4 13
    add s3 s3 s4 
    li s4 0b111110000000
    and s4 s4 s11
    add s3 s3 s4
    slli s4 s4 8
    add s3 s3 s4
    li s4 0b1111100
    and s4 s4 s11
    slli s4 s4 18
    add s3 s3 s4
    mv s11 s3
    j saveInarrayS9

SLLI:
    #all is the same 
    #as above
    li s1 0b000
    li s2 0b10
    bne s1 t0 LW
    bne s2 t5 LW
    li s3 0b00000000000000000001000000010011
    li s4 0b1000000000000
    and s4 s4 s11
    slli s4 s4 13
    add s3 s3 s4 
    li s4 0b111110000000
    and s4 s4 s11
    add s3 s3 s4
    slli s4 s4 8
    add s3 s3 s4
    li s4 0b1111100
    and s4 s4 s11
    slli s4 s4 18
    add s3 s3 s4
    mv s11 s3
    j saveInarrayS9

expand1:
    li s0 0b11111100000000000000000000000000
    add s3 s3 s0
    j back1
expand2:
    li s0 0b11111111111111000000000000000000
    add s3 s3 s0
    j back2
expand3:
    li s0 0b11111100000000000000000000000000
    add s3 s3 s0
    j back3
LW:
    #all is the same 
    #as above
    li s1 0b010
    li s2 0b00
    bne s1 t0 SW
    bne s2 t5 SW
    li s3 0b00000000000000000010000000000011
    li s4 0b1110000000000
    and s4 s4 s11
    slli s4 s4 13
    add s3 s3 s4
    li s4 0b1110000000
    and s4 s4 s11
    li s5 0b10000000000
    add s4 s4 s5
    slli s4 s4 8
    add s3 s3 s4
    li s4 0b1000000
    and s4 s4 s11
    slli s4 s4 16
    add s3 s3 s4
    li s4 0b100000
    and s4 s4 s11
    slli s4 s4 21
    add s3 s3 s4
    li s4 0b11100
    and s4 s4 s11
    li s5 0b100000
    add s4 s4 s5
    slli s4 s4 5
    add s3 s3 s4
    mv s11 s3
    j saveInarrayS9

SW:
    #all is the same 
    #as above
    #actually this stack us very long
    #because in project 1.1
    #the offset must be positive
    # to make it compressible
    # but still the highest positon should
    # of the stack
    # 16
    #is regarded as the signal bits
    # so whether the same
    #is a tought
    #proble
    #after we 
    li s1 0b110
    #try on oj
    # we foud that the offset is unsignaled 
    li s2 0b00
    bne s1 t0 AND
    bne s2 t5 AND
    #现在检查一个offset的[6]会不会是1
    #已经确认了offset[6]有可能是1
    #那么这个到底是有符号的负数呢，还是无符号的证书呢
    li s3 0b00000000000000000010000000100011
    #现在开始重写SW
    #我是傻逼，忘记寄存器了
    #rs2'
    li t0 0b0000000000011100
    and t0 s11 t0
    srli t0 t0 2
    addi t0 t0 8
    slli t0 t0 20
    add s3 s3 t0
    #rs2' 加载完成
    #rs1'
    li t0 0b0000001110000000
    and t0 s11 t0
    srli t0 t0 7
    addi t0 t0 8
    slli t0 t0 15
    add s3 s3 t0
    #rs2' 加载完成
    #第一步是装载imm[4:3]
    li t0 0b0000110000000000
    and t0 s11 t0
    add s3 s3 t0
    #imm[4:3]装载完成
    #装载imm[5]
    li t0 0b0001000000000000
    and t0 s11 t0
    slli t0 t0 13
    add s3 s3 t0
    #imm[5]装载完成
    #装载imm[2]
    li t0 0b0000000001000000
    and t0 s11 t0
    slli t0 t0 3
    add s3 s3 t0
    #imm[2]装载完成
    #破案了，是有符号的
    li t0 0b100000
    and t0 s11 t0
    slli t0 t0 21
    add s3 s3 t0
    # beq t0 x0 NOTNegative_SW
    # li t0 0b11111000000000000000000000000000
    # add s3 s3 t0
    NOTNegative_SW:
    mv s11 s3
    j saveInarrayS9

AND:
    addi x0 x0 0
    #actually this line is
    #no use of this
    #but why we leave
    #an empty line here
    #because we two guys
    #split all types into code
    #two parts
    #and he getg a AND tiel
    #to jump to somewher
    #isjdnow 
CA:
    li s1 0b01
    bne t5 s1 returnError
    #到这里opcode必然是01
    li s1 0b100011
    bne t2 s1 CB
    #这里可以肯定是CA类型
    #s3是rd，s4是rs1，s5是rs2
    #载入rd寄存器和rs1
    li t0 0b0000001110000000 #rd mask
    and s3 s11 t0
    srli s3 s3 7
    addi s3 s3 8
    # s3是32位寄存器指示
    slli s3 s3 7
    # add s1 s1 s3
    #这里rd和rs1是一样的
    slli s4 s3 8
    # add s1 s1 s4

    #载入rs2寄存器
    li t0 0b0000000000011100 #rs2 mask
    and s5 s11 t0
    srli s5 s5 2
    addi s5 s5 8
    # s5是32位寄存器指示
    slli s5 s5 20
    # add s1 s1 s5
    CAND:
        li s1 0b11
        bne t4 s1 COR
        #从这里开始确认了是c.add
        li s1 0b00000000000000000111000000110011 #s1是最后的32位指令
        j MAKECA

    COR:
        li s1 0b10
        bne t4 s1 CXOR
        #从这里开始确认了是c.or
        li s1 0b00000000000000000110000000110011#s1是最后的32位指令
        j MAKECA

    CXOR:
        li s1 0b01
        bne t4 s1 CSUB
        #从这里开始确认了是c.xor
        li s1 0b00000000000000000100000000110011#s1是最后的32位指令
        j MAKECA
    CSUB:
        li s1 0b00
        bne t4 s1 CB
        #从这里开始确认了是c.sub
        li s1 0b01000000000000000000000000110011#s1是最后的32位指令
        j MAKECA

    MAKECA:
        add s1 s1 s3
        add s1 s1 s4
        add s1 s1 s5

        mv s11 s1
        j saveInarrayS9

CB:
    #载入rd、rs1寄存器
    li t6 0b0000001110000000 #rd mask
    and s3 s11 t6
    srli s3 s3 7
    addi s3 s3 8
    #s3 是rd和rs1

    CBEQZ:
        li s1 0b110
        bne t0 s1 CBNEZ
        li s1 0b00000000000000000000000001100011 #s1是最后的32位指令
        j MAKECBTYPE1
    CBNEZ:
        li s1 0b111
        bne t0 s1 CBDown
        li s1 0b00000000000000000001000001100011 #s1是最后的32位指令
        j MAKECBTYPE1
    MAKECBTYPE1:
        slli s3 s3 15
        add s1 s1 s3
        #下面是负数全加1的逻辑,所以如果不是负数就跳过
        li t0 0b0001000000000000 #符号位mask
        and t0 s11 t0
        beq t0 x0 NotNegative_CBEQZ
        li t0 0b11100000000000000000000010000000
        add s1 s1 t0
        NotNegative_CBEQZ:
        #从这里开始只需要1位1位的弄过去就可以了
        li t0 0b0001000000000000 #offset[8]mask
        and t0 s11 t0
        slli t0 t0 16
        add s1 s1 t0
        li t0 0b0000110000000000 #offset[4:3]mask
        and t0 s11 t0
        add s1 s1 t0
        li t0 0b0000000001100000 #offset[7:6]mask
        and t0 s11 t0
        slli t0 t0 21
        add s1 s1 t0
        li t0 0b0000000000011000 #offset[2:1]mask
        and t0 s11 t0
        slli t0 t0 5
        add s1 s1 t0
        li t0 0b0000000000000100 #offset[5]mask
        and t0 s11 t0
        slli t0 t0 23
        add s1 s1 t0
        mv s11 s1
        j saveInarrayS9
     CBDown:
        li s1 0b100
        bne t0 s1 CJ
        #格式是统一的，这里先解析
        #载入rd(rs1)寄存器和
        li t0 0b0000001110000000 #rd mask
        and s3 s11 t0
        srli s3 s3 7
        addi s3 s3 8
        # s3是32位寄存器指示
        slli s3 s3 7
        mv t0 s3
        slli s3 s3 8
        add s3 s3 t0
        #然后把shamt或者imm的[4:0]整进去
        li t0 0b0000000001111100 #imm(shamt)[4:0] mask
        and t0 s11 t0
        slli s4 t0 18
        #下面处理符号位，一样的套路
        li t0 0b0001000000000000 #符号位mask
        and t0 s11 t0
        li s5 0
        beq t0 x0 NOTNegative_CBDown
        li t0 0b1111111
        slli t0 t0 25
        mv s5 t0
        NOTNegative_CBDown:
        li t0 0b00
        bne t3 t0 CSRAI
        li s1 0b00000000000000000101000000010011 #s1是最后的32位指令
        j MAKECBTYPE2
        CSRAI:
        li t0 0b01
        bne t3 t0 CANDI
        li s1 0b01000000000000000101000000010011 #s1是最后的32位指令
        j MAKECBTYPE2
        CANDI:
        li t0 0b10
        bne t3 t0 CJ
        li s1 0b00000000000000000111000000010011 #s1是最后的32位指令
        j MAKECBTYPE2
        MAKECBTYPE2:
        add s1 s1 s3
        add s1 s1 s4
        add s1 s1 s5
        mv s11 s1
        j saveInarrayS9
CJ:
    #到这里必然是CJ了
    li s1 0b00000000000000000000000001101111# jal x0 0
    li s2 0b101
    beq t0 s2 CJ1
    #如果是jal那么rd就是x1
    li t0 00001
    slli t0 t0 7
    add s1 s1 t0
    CJ1:
    #立即数的格式是一样的
    li t0 0b0000100000000000 #offset[4]
    and t0 s11 t0
    slli t0 t0 13
    add s1 s1 t0
    li t0 0b0000011000000000 #offset[9:8]
    and t0 s11 t0
    slli t0 t0 19
    add s1 s1 t0
    li t0 0b0000000100000000 #offset[10]
    and t0 s11 t0
    slli t0 t0 22
    add s1 s1 t0
    li t0 0b0000000010000000 #offset[6]
    and t0 s11 t0
    slli t0 t0 19
    add s1 s1 t0
    li t0 0b0000000001000000 #offset[7]
    and t0 s11 t0
    slli t0 t0 21
    add s1 s1 t0
    li t0 0b0000000000111000 #offset[3:1]
    and t0 s11 t0
    slli t0 t0 18
    add s1 s1 t0
    li t0 0b0000000000000100 #offset[5]
    and t0 s11 t0
    slli t0 t0 23
    add s1 s1 t0
    #接下来是符号位的处理
    li t0 0b1
    slli t0 t0 12 # offset[11] mask
    and t0 s11 t0
    slli t0 t0 8
    beq t0 x0 NOTNegative_JAL
    add s1 s1 t0
    li t0 0b10000000000011111111000000000000
    add s1 s1 t0 
    NOTNegative_JAL:
    mv s11 s1
    j saveInarrayS9
saveInarrayS9:
    # mv a2 s11
    # jal print32
    sw s11 0(s9)
    addi s9 s9 4
    sw s10 0(a6)
    addi a6 a6 4
    lw ra 0(sp)
    addi sp sp 4
    jr ra
    #actually this line is
    #no use of this
    #but why we leave
    #an empty line here
    #because we two guys
    #split all types into code

fixaddress:
li s9 0x10008000
    #actually this line is
    #no use of this
    #but why we leave
    #an empty line here
    #because we two guys
    #split all types into code
    li a6 0 #t3 i
    mv t5 s8
    for:
    beq a6 t5 exit
    slli t4 a6 2
    add s2 s9 t4
    add s3 a7 t4
    lw s11 0(s2)
    li t1 0b1111111
    and t1 t1 s11#t1 opcode
    addi a6 a6 1
# 占用:a6, a7
    #actually this line is
    #no use of this
    #but why we leave
    #an empty line here
    #because we two guys
    #split all types into code
    
    li t2 0b1101111
    bne t1 t2 SB
    li t0 0b1111111111000000000000000000000#imm 1:10
    and t0 t0 s11
    li t2 0b100000000000000000000#imm 11
    and t2 t2 s11
    slli t2 t2 11
    add t0 t0 t2
    srli t0 t0 20
    li t2 0b11111111000000000000#imm 12:19
    and t2 t2 s11
    add t0 t0 t2
    li t2 0b10000000000000000000000000000000#imm 20
    and t2 t2 s11
    srli t2 t2 11
    add t0 t0 t2
    li t1 0b10000000000000000000000000000000#符号位
    and t2 t1 s11
    bne t1 t2 big1
    li t1 0b11111111111000000000000000000000#补齐符号位
    add t0 t0 t1
big1:
    #actually this line is
    #no use of this
    #but why we leave
    #an empty line here
    #because we two guys
    #split all types into code
    addi sp sp -4
    sw ra 0(sp)
    jal for2
    lw ra 0(sp)
    addi sp sp 4
    li t1 0b00000000000000000000111111111111#取出opcode和rd
    and s11 s11 t1
    li t1 0b100000000000#imm 11
    and t1 t0 t1
    slli t1 t1 9
    add s11 s11 t1
    li t1 0b11111111110#imm 1:10
    and t1 t1 t0
    slli t1 t1 20
    add s11 s11 t1
    li t1 0b11111111000000000000#imm 12:19
    and t1 t1 t0
    add s11 s11 t1
    li t1 0b100000000000000000000#imm 20
    and t1 t1 t0
    slli t1 t1 11
    add s11 s11 t1
    sw s11 0(s2)
    j for
SB:
    li t2 0b1100011
    bne t1 t2 for
    # 在这里就能确保是SB类型了
    #首先把imm全部提取出来
    #先放到s4里，然后再看吧
    #已经check s4可以用
    li s4 0
    li t0 0b111100000000 #imm[4:1] mask
    and s4 t0 s11
    srli s4 s4 7
    #imm[4:1] 装载完成
    li t0 0b01111110000000000000000000000000#imm[10:5] mask
    and t0 s11 t0
    srli t0 t0 20
    add s4 s4 t0
    #imm[10:5] 追加完成
    li t0 0b10000000#imm[11] mask
    and t0 s11 t0
    slli t0 t0 4
    add s4 s4 t0
    #imm[11] 追加完成
    li t0 0b10000000000000000000000000000000#imm[12] mask
    and t0 s11 t0
    srli t0 t0 19
    add s4 s4 t0
    #imm[12] 装载完成
    #符号位扩展
    beq t0 x0 big2 #如果imm[12]为0 就不用符号位扩展啦
    li t1 0b11111111111111111110000000000000
    add s4 s4 t1
big2:
    mv t0 s4
    addi sp sp -4
    sw ra 0(sp)
    jal for2
    lw ra 0(sp)
    addi sp sp 4
    #从这里开始再把imm存回去,注意新的imm是t0
    li t1 0b00000001111111111111000001111111 #把原来的imm清除掉
    and s11 s11 t1
    #载入imm[12]
    mv t1 t0
    srli t1 t1 12
    andi t1 t1 1 #t1 就是imm[12]
    slli t1 t1 31 #移动imm[12] 到最开头
    add s11 s11 t1
    #imm[12] 存回去成功
    #载入imm[11]
    mv t1 t0
    srli t1 t1 11
    andi t1 t1 1 #t1 就是imm[11]
    slli t1 t1 7 #移动imm[11] 到
    add s11 s11 t1
    #imm[11] 存回去成功
    #载入imm[10:5]
    mv t1 t0
    srli t1 t1 5
    andi t1 t1 0b111111 #t1 就是imm[10:5]
    slli t1 t1 25 #移动imm[10:5] 到
    add s11 s11 t1
    #imm[10:5] 存回去成功
    #载入imm[4:1]
    mv t1 t0
    srli t1 t1 1
    andi t1 t1 0b1111 #t1 就是imm[4:1]
    slli t1 t1 8 #移动imm[4:1] 到
    add s11 s11 t1
    #imm[4:1] 存回去成功
    
    sw s11 0(s2)
    j for
for2:
    li a1 0b1
    li t3 0 #t3 i
    li t1 0b10000000000000000000000000000000
    and t2 t1 t0
    beq t1 t2 up
down:
    beq x0 t0 sum1
    lw s10 0(s3)
    and s10 s10 a1 
    addi s3 s3 4
    beq a1 s10 sixteen1
    addi t3 t3 1
    addi t0 t0 -4
    j down
sixteen1:    
    addi t3 t3 1
    addi t0 t0 -2
    j down   
sum1:
    li t4 4
    mul t3 t3 t4
    mv t0 t3#得到新imm
    jr ra
up: 
    beq x0 t0 sum2
    addi s3 s3 -4
    lw s10 0(s3)
    and s10 s10 a1 
    beq a1 s10 sixteen2
    addi t3 t3 1
    addi t0 t0 4
    j up
sixteen2:    
    addi t3 t3 1
    addi t0 t0 2
    j up
sum2:
    li t4 -4
    mul t3 t3 t4
    mv t0 t3#得到新imm
    jr ra

#给一个word，一个一个从高位输出它的bit
#a2 是word的值
# 会修改t0,t2,a0,a1,_a2,
print32:
li t2 0x80000000 
li t0 0
li t1 32
loopprint32:
beq t0 t1 endprint32
and a1 a2 t2
srli a1 a1 31
li a0 1
slli a2 a2 1
ecall
addi t0 t0 1
j loopprint32
endprint32:
li a0 11
li a1 10
ecall
jr ra

returnError:
li a0 17
li a1 1
ecall 
    #actually this line is
    #no use of this
    #but why we leave
    #an empty line here
    #because we two guys
    #split all types into code
