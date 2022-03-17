TARGETS=smoothlight
all: $(TARGETS)

smoothlight: smoothlight.c
	gcc $< -o $@ -lxdo $(CFLAGS)

.PHONY: clean
clean:
	rm $(TARGETS)
