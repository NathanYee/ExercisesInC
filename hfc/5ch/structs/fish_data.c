#include <stdio.h>

struct exercise {
  const char *description;
  float duration;
};

struct meal {
  const char *ingredients;
  float weight;
};

struct preferences {
  struct meal food;
  struct exercise exercise;
};

struct fish {
  const char *name;
  const char *species;
  int teeth;
  int age;
  struct preferences care;
};

void fish_description(struct fish f){
  printf("Name: %s\nSpecies: %s\n", f.name, f.species);
  printf("%d years old, %d teeth\n", f.age, f.teeth);
  printf("Feed with %.2f lbs of %s and allow to %s for %.2f hours\n",
  f.care.food.weight, f.care.food.ingredients, f.care.exercise.description,
  f.care.exercise.duration);

}

int main(void){
  struct fish snappy = {"Bob", "Guppy", 10, 5, {{"worms", .1}, {"swim", 15}}};
  fish_description(snappy);
}
