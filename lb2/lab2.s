.data
print_format:
    .string "%d\n"
array:
    .long 64, 4, 65, 32, 128, 16, 96, 48, 80, 15
array_end:

.text
.global main
.type main, @function

main:
    movl $0, %ecx
    movl $array, %ebx
    movl (%ebx), %eax

    jmp ch_bound
loop_start:
    and $64, %eax
    cmpl $64, %eax
    jne lss

    movl (%ebx), %ebp
    sar $1, %ebp
              add %ebp, %ecx

lss:
    xor $64, %eax
    and $64, %eax
    cmpl $64, %eax
    jne less

    add (%ebx), %ecx

less:
    addl $4, %ebx
    movl (%ebx), %eax
ch_bound:
    cmpl $array_end, %ebx
    jne loop_start

    push %ecx
    push $print_format
    call printf
    addl $8, %esp
    movl $0, %ecx
    movl $0, %ebx
    movl $0, %eax
    ret
