/**
 * @package UI
 * @filename TextSelectionPanel.java
 * @author Hanyuu
 * @date 2018/16/19
 * @todo TODO
 */
package UI;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import javax.swing.plaf.basic.BasicBorders;

/**
 * @typename TextSelectionPanel
 * @package UI
 * @description TextSelectionPanel
 * @author Hanyuu
 * @date 2018/11/19
 * @TODO TODO
 */
public class TextSelectionPanel extends JPanel {
	JTextArea texta;
	JTextField textf;
	JButton button;

	/**
	 * 
	 * @author Hanyuu
	 * @date 2018/11/19
	 */
	public TextSelectionPanel() {
		this.setLayout(new FlowLayout());
		this.setName("Hanyuu");
		texta = new JTextArea("texta");
		texta.setBorder(BasicBorders.getTextFieldBorder());
		textf = new JTextField(20);
		textf.setEditable(false);
		button = new JButton("Button");
		button.addActionListener(new CopyActionListerner());
		this.add(texta);
		this.add(textf);
		this.add(button);
	}
		private class CopyActionListerner implements ActionListener{

			/* (non-Javadoc)
			 * @override @see java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent)
			 */
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				textf.setText("");
				String a=texta.getSelectedText();
				textf.setText(a);
			}
			
		}
}
