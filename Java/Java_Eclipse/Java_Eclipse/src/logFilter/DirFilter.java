package logFilter;

import java.io.File;
import java.io.FilenameFilter;
import java.util.regex.Pattern;

/**
 * @package logFilter
 * @description DirFilter
 * @author Hanyuu
 * @date 2018/11/09
 * @TODO TODO
 */
public class DirFilter implements FilenameFilter {
	private Pattern pattern;

	public DirFilter(String regex) {
		pattern = Pattern.compile(regex);
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see java.io.FilenameFilter#accept(java.io.File, java.lang.String)
	 */
	@Override
	public boolean accept(File dir, String name) {
		return pattern.matcher(new File(name).getName()).matches();
	}
}