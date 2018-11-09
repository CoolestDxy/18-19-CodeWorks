package logFilter;

import java.io.File;
import java.io.FilenameFilter;
import java.util.Arrays;
import java.util.Comparator;

/**
 * @package logFilter
 * @description ÁÐ³öÄ¿Â¼
 * @author Hanyuu
 * @date 2018/11/09
 * @TODO TODO
 */
public class DirLister {
	/**
	 * @author Hanyuu
	 * @date 2018/11/09
	 * @return void
	 * @throws none
	 * @param file
	 * @param filter
	 * @param comparator
	 */
	public void listDirectory(File file, FilenameFilter filter, Comparator comparator) {
		if (!file.exists()) {
			System.out.println("Path error");
		} else if (file.isFile()) {
			System.out.println("Not a directory");
		} else {
			File[] files = file.listFiles(filter);
			System.out.println("File list length:" + Integer.toString(files.length));
			Arrays.sort(files, comparator);
			for (int i = 0; i < files.length; ++i) {
				if (files[i].isFile()) {
					System.out.println(files[i]);
				}
			}
		}
	}
}
