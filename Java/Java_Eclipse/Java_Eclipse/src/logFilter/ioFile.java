
package logFilter;

import java.io.File;
import java.io.FilenameFilter;
//import java.lang.reflect.Array;
import java.util.Arrays;

/**
 * @package logFilter
 * @description ioFile
 * @author Hanyuu
 * @date 2018/11/09
 * @TODO TODO
 */
public class ioFile {
	/**
	 * @param file       传入文件
	 * @param fliter     筛选器
	 * @param comparator
	 */
	public void listDirectory(File file, FilenameFilter fliter, DescendingAlphabeticComparator comparator) {
		if (!file.exists()) {
			System.out.println("wrong file path");
		} else if (file.isFile()) {
			System.out.println("not a director");
		} else {
			File[] files = file.listFiles(fliter);
			System.out.println(files.length);
			Arrays.sort(files, comparator);
			for (int i = 0; i < files.length; i++) {
				if (files[i].isFile()) {
					System.out.println(files[i]);
				}
			}

		}

	}

	public static void main(String[] args) {
		ioFile lister = new ioFile();
		DirFilter fliter = new DirFilter(".+log");
		DescendingAlphabeticComparator comparator = new DescendingAlphabeticComparator();
		File file = new File("C:/Windows");
		lister.listDirectory(file, fliter, comparator);
	}

}
