package LogFilter;

import java.io.File;
import java.util.Comparator;

public class DirLister {
	public void listDirectory(File file, FilenameFilter filter, Comparator comparator){
	if(!file.exists()){
		System.out.println("Path error");
	}
	else if(file.isFile()){
		System.out.println("Not a directory");
	}
	else{
		File[] files=file.listFiles(filter);
	}
	}
}
