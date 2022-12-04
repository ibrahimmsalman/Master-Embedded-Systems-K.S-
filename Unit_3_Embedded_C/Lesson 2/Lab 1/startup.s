@@ (learn-in-depth)
.globl reset
reset:
        ldr sp, =Stack_top
		bl main
stop:   b stop		