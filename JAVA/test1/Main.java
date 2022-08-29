package test1;
import java.util.Arrays;
//https://school.programmers.co.kr/learn/courses/30/lessons/42885

public class Main {
	public static int solution(int[] people, int limit) {
		int answer = 0;
        int min = 0;                 // 체크할 첫번째 포인터(작은 몸무게부터)
        int max = people.length -1;  // 체크할 두번째 포인터(큰 몸무게부터)
        
        Arrays.sort(people);         // 배열 정렬
        while (min <= max){          // 남은 배열 요소가 한개일 때에도 진행해야하므로 “<=“
            answer++;                // 배를 띄운다
            if(people[min] + people[max] <=limit)
                min++;               // 2명이 모두 탑승하므로 첫번째 포인터 증가
            max--;                   // 항상 두번째 포인터 증가.
		}
		return answer;
	}
	
	
	public static void main(String[] main) {
		int[] arr1 = {70,50,80,50};
		System.out.println(solution(arr1, 100));
		
		int[] arr2 = {70,80,50};
		System.out.println(solution(arr2, 100));
	}
}

