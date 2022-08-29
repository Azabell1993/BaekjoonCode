package test2;
//https://school.programmers.co.kr/learn/courses/30/lessons/42587

public class Main {
	public static String solution(String s) {
		String answer = "";
		int idx = 0;
		String[] strArr = s.split("");
		for(int i=0; i<strArr.length; i++) {
			if(strArr[i].equals(" ")) idx = 0;
			else {
				if(idx % 2 == 0) {
					strArr[i] = strArr[i].toUpperCase();
				} else {
					strArr[i] = strArr[i].toLowerCase();
				}
				idx++;
			}
			answer = answer + strArr[i];
		}
		return answer;
	}
	
	public static void main(String[] main) {
		String str = "try hello world";
		
		System.out.println(solution(str));
	}
}
