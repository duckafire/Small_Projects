import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingUtilities;

public class window{
	public static void main(String[] args){
		JFrame panel;
		JLabel messa;
		
		panel = new JFrame("window-java");
		panel.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
		panel.setSize(500, 500);

		messa = new JLabel("Hello world!", JLabel.CENTER);

		panel.add(messa);
		panel.setVisible(true);
	}
}
