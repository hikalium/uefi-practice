struct EFI_SYSTEM_TABLE {
  char _buf[60];
  struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL {
    unsigned long long _buf;
    unsigned long long (*OutputString)(
        struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
        short unsigned int *String);
    unsigned long long _buf2[4];
    unsigned long long (*ClearScreen)(
        struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This);
  } * ConOut;
};

void efi_main(void *ImageHandle, struct EFI_SYSTEM_TABLE *SystemTable) {
  SystemTable->ConOut->ClearScreen(SystemTable->ConOut);
  SystemTable->ConOut->OutputString(SystemTable->ConOut,
                                    L"Hello, UEFI! This is hikalium!!!");
  while (1)
    ;
}
