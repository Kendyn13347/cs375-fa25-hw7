// /**
//  * An example of an entry point that would reside in the interrupt
//  * vector. This entry point is for interrupt number 0x30.
//  */
// //.func intr30_stub
// //intr30_stub:
//     pushl %ebp /* Frame pointer */
//     pushl $0 /* Error code */
//     pushl $0x30 /* Interrupt vector number */
//     jmp intr_entry
// .endfunc

// /* Main interrupt entry point.
//  *
//  * An internal or external interrupt starts in one of the
//  * intrNN_stub routines, which push the `struct intr_frame'
//  * frame_pointer, error_code, and vec_no members on the stack,
//  * then jump here.
//  *
//  * We save the rest of the `struct intr_frame' members to the
//  * stack, set up some registers as needed by the kernel, and then
//  * call intr_handler(), which actually handles the interrupt.
//  *
//  * We "fall through" to intr_exit to return from the interrupt.
//  */
// .func intr_entry
// intr_entry:
//     /* Save caller's registers. */
//     pushl %ds
//     pushl %es
//     pushl %fs
//     pushl %gs
//     pushal

//     /* Set up kernel environment. */
//     cld                 /* String instructions go upward. */
//     mov $SEL_KDSEG, %eax /* Initialize segment registers. */
//     mov %eax, %ds
//     mov %eax, %es
//     leal 56(%esp), %ebp /* Set up frame pointer. */
//     /* Call interrupt handler. */
//     pushl %esp
// .globl intr_handler
//     call intr_handler
//     addl $4, %esp
// .endfunc

// /* Interrupt exit.
//  *
//  * Restores the caller's registers, discards extra data on the
//  * stack, and returns to the caller.
//  *
//  * This is a separate function because it is called directly when
//  * we launch a new user process (see start_process() in
//  * userprog/process.c). */
// //.globl intr_exit
// .func intr_exit
// intr_exit:
//     /* Restore caller's registers. */
//     popal
//     popl %gs
//     popl %fs
//     popl %es
//     popl %ds

//     /* Discard `struct intr_frame' vec_no, error_code,
//        frame_pointer members. */
//     addl $12, %esp

//     /* Return to caller. */
//     iret
// .endfunc
