import java.util.Scanner;

class StackOverflow extends Exception{
	public StackOverflow(String message){
		System.out.printf(message);
	}
}

class StackUnderflow extends Exception{
	public StackUnderflow(String message){
		System.out.printf(message);
	}
}

public class TheStack{
	private static final int MAX_SIZE = 200;
	private final int top = 0;
	private int spotFilled = 0;
	private char v[] = new char[MAX_SIZE];
	
	private void push(char c) throws StackOverflow{
		this.spotFilled++;
		
		if(this.spotFilled >= MAX_SIZE){
			this.spotFilled = MAX_SIZE;
			throw new StackOverflow("Error, cannot push, stack has reached max size. Consider popping to add new value\n");
		}else{
			char indexBuff = this.v[0];
			this.v[0] = c;
			
			for(int i = 1; i < MAX_SIZE; i++){
				char secondIndexBuff = this.v[i];
				this.v[i] = indexBuff;
				indexBuff = secondIndexBuff;
			}
		}
	}
	
	private char pop() throws StackUnderflow{
		this.spotFilled--;
		
		if(this.spotFilled < 0){
			this.spotFilled = 0;
			throw new StackUnderflow("Error, cannot pop, stack has reached min size. Consider adding values to pop them\n");
		}else{
			for(int i = 1; i < MAX_SIZE; i++){
				this.v[i-1] = v[i];
			}
		}
		
		return this.v[top];
	}
	
	private void printStack(){
		for(char c : v) System.out.printf("%c ", c);
		System.out.printf("\n");
	}
	
	public void exe(){
		String command = "";
		char lastPop;
		Scanner in = new Scanner(System.in);
		
		while(!command.equalsIgnoreCase("exit")){
			System.out.printf("$ ");
			int space = 0;
			try{
				command = in.nextLine();
				String program = command.substring(0, 3);
				
				System.out.println(program);
				
				if(program.equalsIgnoreCase("pus")){
					space = command.indexOf(" ");
					char arg = command.substring(space + 1).charAt(0);
					this.push(arg);
				}else if(program.equalsIgnoreCase("pop")) lastPop = this.pop();
				else if(program.equalsIgnoreCase("pri")) this.printStack();
				else System.out.printf("Unknown command: \"%s\"\n", command);
			} catch (StackOverflow so){
				continue;
			} catch (StackUnderflow su){
				continue;
			} catch (StringIndexOutOfBoundsException sioobe){
				System.out.printf("Error with input\nSpace: %d\n", space);
				continue;
			}
			
		}
	}
	
	
	
	public static void main(String args[]){
		TheStack stack = new TheStack();
		stack.exe();
	}
}


