/*
 * This bot plays a guessing game with itself
*/

public class GuessingBot{
  private final static int MAX_GUESS = 1000000;

  public void run(){
    System.out.println("Bot guessing number in the range 1-100.");

    char direction = 'n';
    int number = 50;
    int rang = 100;
    int randNumber = (int)(Math.random() * rang) + 1;
    int interval = rang / 2;
    int tries = 0;

    while(true){
      if(number > randNumber){
        System.out.println("Lower");
        direction = 'l';
      }else if(number < randNumber){
        System.out.println("Higher");
        direction = 'h';
      }else{
        System.out.println("That's right! rand: " + randNumber + " = " + "you: " + number);
        break;
      }

      if(direction == 'l'){
        rang -= interval;
        number = (int)(Math.random() * rang) + 1;
        interval /= 2;
      }else if(direction == 'h'){
        rang += interval;
        number = (int)(Math.random() * rang) + 1;
        interval /= 2;
      }

      if(interval <= 0) interval = 1;

      tries++;

      if(tries == MAX_GUESS){
        System.out.println("Sorry, try limit exceeded. The number is: " + tries);
        break;
      }
    }

    System.out.println("tries: " + tries);
  }

  public static void main(String args[]){
    new GuessingBot().run();
  }
}
