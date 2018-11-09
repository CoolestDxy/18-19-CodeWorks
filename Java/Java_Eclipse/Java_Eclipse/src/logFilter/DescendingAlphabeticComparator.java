package logFilter;

import java.util.Comparator;

/**
 * @package logFilter
 * @description DescendingAlphabeticComparator
 * @author Hanyuu
 * @date 2018/11/09
 * @TODO TODO
 */
public class DescendingAlphabeticComparator implements Comparator {

	/*
	 * (non-Javadoc)
	 * 
	 * @override @see java.util.Comparator#compare(java.lang.Object,
	 * java.lang.Object)
	 */
	@Override
	public int compare(Object a, Object b) {
		return -a.toString().compareTo(b.toString());
	}

	/**
	 * @param a
	 * @param b
	 * @return
	 * @author Hanyuu
	 * @date 2018/11/09
	 */
	public boolean equal(Object a, Object b) {
		return !a.toString().equals(b.toString());
	}
}