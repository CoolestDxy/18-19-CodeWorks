package src;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Iterator;
// import java.time.*;

public class BenchMarkForArrayListAndLinkedLIst {
	BenchMarkForArrayListAndLinkedLIst()
	{
		arrList=new ArrayList<String>();
		lnkList=new LinkedList<String>();
	}
	public static final long maxSize=10000;
	public static final long repeat=100000;
	ArrayList<String> arrList;
	LinkedList<String> lnkList;
	public String getValueArr(int ind) {
		return arrList.get(ind);
	}
	public String getValueLst(int ind) {
		return lnkList.get(ind);
	}
	public void travArr()
	{
		Iterator<String> a=arrList.iterator();
		while (a.hasNext()) {
			a.next();
		}
	}
	public void travLnk() {
		Iterator<String> a=lnkList.iterator();
		while(a.hasNext()) {
			a.next();
		}
	}
	public void addArr(String ins) {
		for(int i=0;i<maxSize;++i) {
			arrList.add(ins);
		}
	}
	public void addLnk(String ins) {
		for(int i=0;i<maxSize;++i) {
			lnkList.add(ins);
		}
	}
	public void delArr() {
		while(arrList.size()>0) {
			arrList.remove(0);
		}
	}
	public void delLnk() {
		while(lnkList.size()>0) {
			lnkList.remove(0);
		}
	}
	public static void main(String []args) {
		BenchMarkForArrayListAndLinkedLIst exp=new BenchMarkForArrayListAndLinkedLIst();
		
		long startTime=System.currentTimeMillis();
		exp.addArr("Hanyuu");
		long endTime=System.currentTimeMillis();
		System.out.println(endTime-startTime);
		
		startTime=System.currentTimeMillis();
		exp.addLnk("Hanyuu");
		endTime=System.currentTimeMillis();
		System.out.println(endTime-startTime);

		startTime=System.currentTimeMillis();
		for (int i=0;i<BenchMarkForArrayListAndLinkedLIst.maxSize;++i) {
			exp.getValueArr(i);
		}
		endTime=System.currentTimeMillis();
		System.out.println(endTime-startTime);
		
		startTime=System.currentTimeMillis();
		for (int i=0;i<BenchMarkForArrayListAndLinkedLIst.maxSize;++i) {
			exp.getValueLst(i);
		}
		endTime=System.currentTimeMillis();
		System.out.println(endTime-startTime);
		
		startTime=System.currentTimeMillis();
		exp.travArr();
		endTime=System.currentTimeMillis();
		System.out.println(endTime-startTime);
		
		startTime=System.currentTimeMillis();
		exp.travLnk();
		endTime=System.currentTimeMillis();
		System.out.println(endTime-startTime);
		
		startTime=System.currentTimeMillis();
		exp.delArr();
		endTime=System.currentTimeMillis();
		System.out.println(endTime-startTime);
		
		startTime=System.currentTimeMillis();
		exp.delLnk();
		endTime=System.currentTimeMillis();
		System.out.println(endTime-startTime);
	}
}

