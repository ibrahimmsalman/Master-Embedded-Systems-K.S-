#prebared by Ibrahim Salman (learn in depth)
CC=arm-none-eabi-
CFLAGS=	-mcpu=cortex-m4	-gdwarf-2 -g
INCS=-I	.
LIBS=
SRC	=	$(wildcard *.c)
OBJ	=	$(SRC:.c=.o) # same as OBJS = $(patsubst %.c,%.o,$SRC)
As	=	$(wildcard *.s)
AsOBJ	=	$(As:.s=.o)
Project_name	= Embedded_C_Lesson_4_Lab_3

All:	$(Project_name).bin

%.o:	%.s
	$(CC)as.exe		$(CFLAGS) $<	-o	$@ 
%.o:	%.c
	$(CC)gcc.exe	$(CFLAGS)	$(INCS)	-c	$<	-o $@

$(Project_name).elf:	$(OBJ)	$(AsOBJ)
	$(CC)ld.exe	-T linker_script.ld	$(LIBS)	$(OBJ)	$(AsOBJ)	-o	$@	-Map=Map_file.map
	
$(Project_name).bin:	$(Project_name).elf	
	$(CC)objcopy.exe	-O binary	$<	$@
	
clean_all:
	rm	*.o	*~	*.elf	*.bin

clean:
	rm	*.elf	*.bin