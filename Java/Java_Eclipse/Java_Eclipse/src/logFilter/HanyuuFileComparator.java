package logFilter;

import java.util.Comparator;
import java.util.Date;
import java.io.File;

/**
 * @package logFilter
 * @description DescendingAlphabeticComparator
 * @author Hanyuu
 * @date 2018/11/09
 * @TODO TODO
 */
public class HanyuuFileComparator implements Comparator<File> {
	/*
	 * (non-Javadoc)
	 * 
	 * @override @see java.util.Comparator#compare(java.lang.Object,
	 * java.lang.Object)
	 */
	private int flag = 1;

	/**
	 * @param flag 升序：非0  降序：0
	 * @author Hanyuu
	 * @date 2018/11/11
	 */
	HanyuuFileComparator(int flag) {
		if (flag == 0) {
			flag = -1;
		}
	}

	/* (non-Javadoc)
	 * @override @see java.util.Comparator#compare(java.lang.Object, java.lang.Object)
	 */
	@Override
	public int compare(File a, File b) {
//		return flag * (int)((a.lastModified()-b.lastModified()));
		Date aa=new Date(a.lastModified());
		Date bb=new Date(b.lastModified());
		return flag*aa.compareTo(bb);
	}

	/**
	 * @param a
	 * @param b
	 * @return
	 * @author Hanyuu
	 * @date 2018/11/09
	 */
	public boolean equal(File a, File b) {
		return a.lastModified()==b.lastModified();
	}
}