// dosya hash karsilastirma
#include <stdio.h>
#include <string.h>
//8crc32 ,16crc64,40sha-1,64sha256,128sha512,56sha224,96sha384,32md5

// gets function is dangerous DONT use it!!!
char hash[129],hash2[129];
int i,j=0;

int main(int argc, char const *argv[]) {
  printf("Supported cheksum types: \n");
  printf("sha-1,sha256,sha224,sha384,sha512,md5,crc32,crc64.\n");
  printf("\nPlease enter a validated hash value: \n\n");
  fgets(hash, sizeof(hash), stdin);
  printf("\nPlease enter a hash you want to compare: \n\n");
  fgets(hash2, sizeof(hash2), stdin);

  // stdin means standard input
  //printf("%s", hash);
  // initializer element is not constant so we cannot place len variable out of main block
// removing unnecessary /n that fgets creates.
  int len = strlen(hash);
if (len > 0 && hash[len-1] && hash2[len-1] == '\n')
  hash[len-1] = '\0';
  hash2[len-1] = '\0';
  
while (strlen(hash) > 0) {
if (strlen(hash) != strlen(hash2)) {
  printf("Please enter a same length values!\n");
  return 0;
}
 break;
}

while (strlen(hash) >= 0) {
if (strlen(hash) == 8 || strlen(hash) == 16 || strlen(hash) == 32 || strlen(hash) == 56 ||
strlen(hash) == 96 || strlen(hash) == 64 || strlen(hash) == 40
 || strlen(hash) == 128){
break;
}
    else
    printf("Please enter a valid hash value!\n");
return 0;
}

  for (i = 0; i < strlen(hash); i++) {
    if (hash[i] == hash2[i]) {
      j++;
    }
  }
  printf("\nMatched Hash value length: %d",j);

  if (j == strlen(hash))
    printf("\n\nYour file hash was correct!");
  else
  printf("\n\nPlease download your file again!");

  getchar();
}
