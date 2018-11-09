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

	@Override
	public int compare(Object a, Object b) {
		return -a.toString().compareTo(b.toString());
	}

	public boolean equal(Object a, Object b) {
		return a.toString().equals(b.toString());
	}
}