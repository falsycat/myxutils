all: smoothlight

smoothlight: smoothlight.c
	gcc $< -o $@ -lxdo
