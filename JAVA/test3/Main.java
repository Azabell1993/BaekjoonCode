package test3;
public class Main {
	public static void main(String[] main) {
		String str = "23four5six7";
		String [] arr = {"zero", "one","two","three","four","five","six","seven","eight","night"};
        for(int i= 0; i<arr.length; i++){
            str = str.replaceAll(arr[i], Integer.toString(i));
        }
		
        System.out.println(str);
	}
}
