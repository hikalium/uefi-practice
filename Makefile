all: $(TARGET)

TARGET = BOOTX64.EFI
SRCS = main.c
OVMF_PATH = OVMF/OVMF.fd
FS_DIR = ./fs
EFI_INSTALL_DIR = $(FS_DIR)/EFI/BOOT/

BOOTX64.EFI: $(SRCS)
	x86_64-w64-mingw32-gcc -Wall -Wextra -e efi_main -nostdlib -Wl,--subsystem,10 -o $@ $<

run: $(TARGET)
	mkdir -p $(EFI_INSTALL_DIR)
	cp $(TARGET) $(EFI_INSTALL_DIR)
	qemu-system-x86_64 -bios $(OVMF_PATH) -hda fat:rw:fs 

clean:
	rm -rf fs

.PHONY: clean
