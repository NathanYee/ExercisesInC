# Reflection 1 - Software Systems - Nathan Yee

## Written sprint reflection

These were my semester learning goals that I made during sprint 0:
* get good at C,
  * Read Head First C and worked through textbook examples to both internalize and have copy and paste-able examples of C code.
* internalize memory management
  * Head first C chapter 2
    Still not feeling the best here. I need to play around with memory a lot more.
* do something robotics related
  * No progress here. As I'm learning more about robotics in my other class, I will need to reevaluate this goal.
* develop a comfortable work flow
  * Set up atom with packages (vim-mode-plus, gcc-make-run) to help my development speed.
    As of right now, I'm finding these packages useful for developing speed.
    I am still looking for a proper debugger.
* collaborate and work in parallel
  * When our team is meeting, we are able to efficiently collaborate and work together.
    Of more concern, we haven't had any small meetings between less than 3 members of the team.
    I feel like more smaller meetings would allow us to work on the project at a much faster rate.
* work with low resource mobile processors
  * Our choice to use an Arduino is helping here.
    To gain more experience with low resource computers, I will push the Arduino to its absolute limits for our one-bit DAC.
* stay organized as team
  * We have stayed organized and have kept up consistent team communication and Trello usage.
    Stand-ups and next meeting planning have also proved necessary to stay together.
    As scrum master, I'm a little afraid that we aren't moving fast enough in both the textbook and the project.


## Links to Head First C exercises

Read:
* Chapter 1
  * [ch1 work/notes/exercises](../exercises/ex01)
  * Did all required tasks. I still don't know how to read assembly.
* Chapter 2
  * Spent 3ish hours on stack.c but not finished.
  * [ch2 exercises](../exercises/ex02)
  * [ch2 work/notes](../hfc/2ch)
* Chapter 2.5
  * Read and did examples from textbook. No exercise work yet.
  * [ch2.5 work/notes](../hfc/2.5ch)




## Think OS reading question answers

Read TOS 1-3  
[Did TOS reading questions 1-3](../reading_questions/thinkos.md)


## Exam question(s) and solution

How do you copy the contents of an array into another array. Why does the code below not work?

    #include <stdio.h>

    int main() {
      int foo[3] = {1,2,3};
      int bar[3];

      for (int i = 0; i < 3; i++) {
        printf("%d\n", foo[i]);
      }

      foo = bar;

      for (int i = 0; i < 3; i++) {
        printf("%d\n", bar[i]);
      }

      return 0;
    }

The above code does not work because you can just say that an array is equal to another array. There are two potential solutions here. One, you could make a assign a pointer to point to bar. Or, you could write a for loop to iterate through values of foo and assign them to the corresponding indexes of bar.
