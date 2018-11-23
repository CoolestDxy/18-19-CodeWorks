/**
 * @package UI
 * @filename textDemo.java
 * @author Hanyuu
 * @date 2018/24/21
 * @todo TODO
 */
package UI;

import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;

import java.awt.*;

/**
 * @typename textDemo
 * @package UI
 * @description textDemo
 * @author Hanyuu
 * @date 2018/11/21
 * @TODO TODO
 */
public class textDemo {
	JFrame frame;
	JTextArea text;

	public textDemo() {
		frame = new JFrame();
		frame.setTitle("Editor");
		text = new JTextArea();
		text.getDocument().addDocumentListener(new TextChangeListener());
		frame.add(text);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(500, 200);
		frame.setVisible(true);

	}

	private class TextChangeListener implements DocumentListener {

		boolean changed = false;

		/*
		 * (non-Javadoc)
		 * 
		 * @override @see
		 * javax.swing.event.DocumentListener#insertUpdate(javax.swing.event.
		 * DocumentEvent)
		 */
		@Override
		public void insertUpdate(DocumentEvent e) {
			// TODO Auto-generated method stub
			if (!changed) {
				frame.setTitle(frame.getTitle() + "[*]");
				changed = true;
			}
		}

		/*
		 * (non-Javadoc)
		 * 
		 * @override @see
		 * javax.swing.event.DocumentListener#removeUpdate(javax.swing.event.
		 * DocumentEvent)
		 */
		@Override
		public void removeUpdate(DocumentEvent e) {
			// TODO Auto-generated method stub
			if (!changed) {
				frame.setTitle(frame.getTitle() + "[*]");
				changed = true;
			}
		}

		/*
		 * (non-Javadoc)
		 * 
		 * @override @see
		 * javax.swing.event.DocumentListener#changedUpdate(javax.swing.event.
		 * DocumentEvent)
		 */
		@Override
		public void changedUpdate(DocumentEvent e) {
			// TODO Auto-generated method stub
			if (!changed) {
				frame.setTitle(frame.getTitle() + "[*]");
				changed = true;
			}
		}
	}

	/**
	 * @param args
	 * @author Hanyuu
	 * @date 2018/11/21
	 */
	public static void main(String[] args) {
		textDemo demo = new textDemo();
	}
}
