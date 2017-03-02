typedef struct cell_phone {
  int cell_no;
  const char *wallpaper;
  float minutes_of_charge;
} phone;

int main(void){
  phone p = {1234567, "basil.png", 57.3};
  printf("Number: %d\n", p.cell_no);
}
