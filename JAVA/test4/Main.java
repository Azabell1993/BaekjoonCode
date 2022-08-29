package test4;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
	public static int solution(int[] priorities, int location) {
		int answer = 0;
		int maximum;
		
		Deque <Integer> index_dq = new ArrayDeque<Integer>(); 	//priorities의 인덱스 역할 큐선언
	
		for(int i=0; i<priorities.length; i++)	//인덱스 채우기
			index_dq.addLast(i);
		
		while(true) {
			maximum = max(priorities);          //최대 우선순위 도출
            int index = index_dq.peek();        //priorities의 0번째 인덱스 부터 탐색
            if (priorities[index] < maximum){   //현재 위치의 값보다 더 큰 우선순위가 있다면
                index_dq.addLast(index);        //현재 인덱스를 Queue의 맨뒤로 이동
            	index_dq.removeFirst();
            }else{                              //현재 위치의 우선순위가 가장 크다면
                answer += 1;
                priorities[index] = 0;          //그 아이는 출력, 우선순위는 0(제일 작게) 변경
                if (index == location) {        //현 위치가 location과 같다면 순번(answer)를 리턴
                    return answer;

				}
			}
		}
	}
	
	static int max(int[] arr) {
		int max = arr[0];
		for(int i=0; i<arr.length; i++) {
			if(arr[i] > max) max = arr[i];
		}
		return max;
	}
	
	public static void main(String[] main) {
		int[] arr1 = {2, 1, 3, 2};
		System.out.println(solution(arr1, 2));
		
		int[] arr2 = {1, 1, 9, 1, 1, 1};
		System.out.println(solution(arr2, 0));
	}
}
