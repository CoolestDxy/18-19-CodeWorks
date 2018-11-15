/**
 * @package collectBenchmark
 * @filename Benchmark.java
 * @author Hanyuu
 * @date 2018/58/15
 * @todo TODO
 */
package collectBenchmark;

import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Vector;
import java.util.Iterator;

/**
 * @typename Benchmark
 * @package collectBenchmark
 * @description Benchmark
 * @author Hanyuu
 * @date 2018/11/15
 * @TODO TODO
 */
public class Benchmark {
	static final long repeat = 100000;
	private LinkedList<Integer> ll;
	private ArrayList<Integer> al;
	private Vector<Integer> v;
	private Iterator<Integer> iter;
	long time;

	public void timeStart() {
		System.gc();
		time = System.currentTimeMillis();
	}

	public void timeRecord() {
		System.out.println("【time】：" + (Long) (System.currentTimeMillis() - time));
		System.gc();
		time = System.currentTimeMillis();
	}

	/**
	 * 
	 * @author Hanyuu
	 * @date 2018/11/15
	 */
	Benchmark() {
		ll = new LinkedList<Integer>();
		al = new ArrayList<Integer>();
		v = new Vector<Integer>();
		timeStart();
		for(int i=0;i<Benchmark.repeat;i++) {
			ll.push(i);
		}
		timeRecord();
		for(int i=0;i<Benchmark.repeat;i++) {
			al.add(i);
		}
		timeRecord();
		for(int i=0;i<Benchmark.repeat;i++) {
			v.add(i);
		}
		timeRecord();
		for(int i=0;i<Benchmark.repeat;i++) {
			ll.get(i);
		}
		timeRecord();
		for(int i=0;i<Benchmark.repeat;i++) {
			al.get(i);
		}
		timeRecord();
		for(int i=0;i<Benchmark.repeat;i++) {
			v.get(i);
		}
		timeRecord();
		iter=ll.iterator();
		while(iter.hasNext()) {
			iter.next();
		}
		timeRecord();
		iter=al.iterator();
		while(iter.hasNext()) {
			iter.next();
		}
		timeRecord();
		iter=v.iterator();
		while(iter.hasNext()) {
			iter.next();
		}
		timeRecord();
		for(int i=0;i<Benchmark.repeat;i++) {
			ll.pop();
		}
		timeRecord();
		for(int i=0;i<Benchmark.repeat;i++) {
			al.remove(0);
		}
		timeRecord();
		for(int i=0;i<Benchmark.repeat;i++) {
			v.remove(0);
		}
		timeRecord();
	}

	/**
	 * @param args
	 * @author Hanyuu
	 * @date 2018/11/15
	 */
	public static void main(String[] args) {
		Benchmark exp=new Benchmark();
	}
}
