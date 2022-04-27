# Project2.2

• Tests for a completed CPU have been included with the lab starter code. You can run them with the command **`./cpu-sanity.sh`**. See the Testing section for information on how to interpret your test output

Please read this document *CAREFULLY* as there are key differences between the processor we studied in class and the processor you will be designing for this project.

# Resources

[项目页](https://robotics.shanghaitech.edu.cn/courses/ca/22s/projects/2.2/)

[RISC-V Green Card](https://robotics.shanghaitech.edu.cn/courses/ca/19s/notes/riscvcard.pdf)

[RISC-V ISA Manual](https://content.riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf)

[What do the different wire colors mean?](http://www.cburch.com/logisim/docs/2.7/en/html/guide/bundles/colors.html)

---

**1) Processor**

cpu.circ

You are responsible for constructing the entire datapath and control from scratch.

two-cycle pipeline, with IF in the first stage and ID, EX, MEM, and WB in the second stage.

**1.5) Memory**

[Untitled](https://www.notion.so/0937afb772cf4f7ebf00eecf7b9b1740)

Note that the memory is word-addressable, meaning given an address, it will return 4-byte data.

# **2) The Instruction Set Architecture**

![Untitled](Project2%202%202e40f91bfcfc4323bd01e70f59c5df21/Untitled.png)

ISA指令见主页

[https://robotics.shanghaitech.edu.cn/courses/ca/22s/projects/2.2/](https://robotics.shanghaitech.edu.cn/courses/ca/22s/projects/2.2/)

[Project 2.2 - Computer Architecture I - ShanghaiTech University](https://robotics.shanghaitech.edu.cn/courses/ca/22s/projects/2.2/)

For **I, S, B, U, and J type** instructions,需要提取 immediate . You may want to create an **Immediate Generator subcircuit** to do this. Remember that in RISC-V, all immediates that leave the immediate generator are **32-bits and sign-extended**!

![Untitled](Project2%202%202e40f91bfcfc4323bd01e70f59c5df21/Untitled%201.png)

**3) Controls**

The other method is **hard-wired control**, which is usually the preferred approach for RISC architectures like MIPS and RISC-V. Hard-wired control uses "AND", "OR", and "NOT" gates (along with the various components we've learned can be built from these gates, like MUXes and DEMUXes) to produce the appropriate control signals. The **instruction decoder**  takes in an instruction and outputs all of the control signals for that instruction.

![Untitled](Project2%202%202e40f91bfcfc4323bd01e70f59c5df21/Untitled%202.png)

**4) Pipelining**

Your processor will have a 2-stage pipeline:

1. **Instruction Fetch:** An instruction is fetched from the instruction memory. (Note: while you can, please do not calculate jump address in this stage. Instead, you should try to deal with the *jump control hazard*.)
2. **Execute:** The instruction is decoded, executed, and committed (written back). This is a combination of the remaining stages of a normal five-stage RISC-V pipeline.

First, make sure you understand what hazards you will have to deal with.

注意到如果是跳转命令，因为上面的流水线，就有可能会fetch到错误的命令，此时需要使用mux给nop来“kill”指令，nop指令可以认为是0x00000013, or addi x0, x0, 0。不过要注意只有当fetch到错误的指令的时候才kill不要动不动就kill。（也不要使用别的方法规避这个hazard）

2-stage相对于单生产线来说理应除了一个周期的延时和跳转的麻烦事外完全一样，在这个two-stage pipeline design. Some things to consider:

- Will the IF and EX stages have the same or different PC values?
- Do you need to store the PC between the pipelining stages?
- To MUX a nop into the instruction stream, do you place it *before* or *after* the instruction register?
- What address should be requested next while the EX stage executes a nop? Is this different than normal?
    
    

# **Getting Started: A Guide**

以实现a simple I-type instruction, addi 为例

**Stage 1: Instruction Fetch**

注意地址截断了高18位，所以地址是个a word address.（？）

Remember that we're implementing a 2-stage pipelined processor, so the IF stage is separate from the remaining stages. What circuitry separates the different stages of a pipeline? Do you need to add anything?

**Stage 2: Instruction Decode**

![Untitled](Project2%202%202e40f91bfcfc4323bd01e70f59c5df21/Untitled%203.png)

![Untitled](Project2%202%202e40f91bfcfc4323bd01e70f59c5df21/Untitled%204.png)

**Stage 3: Execute(**ALU stage**)**

ALU_Sel 电路