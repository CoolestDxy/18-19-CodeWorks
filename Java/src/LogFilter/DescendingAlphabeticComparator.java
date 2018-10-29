package LogFilter;

import java.util.Comparator;

public class DescendingAlphabeticComparator implements Comparator{
	public int compare(Object a, Object b) {
		return -a.toString().compareTo(b.toString());
	}
	public boolean equal(Object a, Object b) {
		return a.toString().equals(b.toString());
	}
}