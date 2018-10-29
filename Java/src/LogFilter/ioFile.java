package LogFilter;

//import LogFilter.DirFilter;

import java.io.File;
import java.io.FilenameFilter;
//import java.lang.reflect.Array;
import java.util.Arrays;

public class ioFile {
	public void listDirectory(File file, FilenameFilter fliter, DescendingAlphabeticComparator comparator) {
		if (!file.exists()) {
			System.out.println("wrong file path");
		} else if (file.isFile()) {
			System.out.println("not a director");
		} else {
			File[] files = file.listFiles(fliter); // javadoc 用的FilenameFilter
			System.out.println(files.length);
			Arrays.sort(files, comparator);     //看网上示例 用的实现完后的版本
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
