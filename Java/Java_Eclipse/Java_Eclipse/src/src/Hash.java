package src;

import java.util.ArrayList;
import java.util.Arrays;

public class Hash {
	public static void main(String args[]) {
		String [] str1=new String[10];
		String [] str2=new String[10];
		Arrays.fill(str1, "Hanyuu");
		Arrays.fill(str2, "Hanyuu");
		System.out.println(Arrays.hashCode(str1));
		System.out.println(Arrays.hashCode(str2));
		System.out.println(Arrays.equals(str1,str2));
		System.out.println(Arrays.toString(str1));
		ArrayList<String> list=new ArrayList<String>();
		list.add("Hanyuu");
		System.out.println(list.size());
		String[] listA=new String[10];
		System.out.println(listA.length);
		ArrayList listB=new ArrayList();
		listB.add(2);
		listB.add(listB);
		System.out.println(listB.get(1).toString());
		listB.ensureCapacity(100);
		System.out.println(listB.size());
	
	}
}
