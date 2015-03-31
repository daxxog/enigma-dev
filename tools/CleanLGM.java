/* CleanLGM.java
 * Cleans LateralGM Preferences
 * (c) 2015 David (daXXog) Volm ><> + + + <><
 * Released under Apache License, Version 2.0:
 * http://www.apache.org/licenses/LICENSE-2.0.html  
 */ 

import java.util.prefs.Preferences;

public class CleanLGM {
	public static void main(String[] args) {
		Preferences PREFS = Preferences.userRoot().node("/org/lateralgm");
		PREFS.remove("FILE_RECENT");
		System.out.println("Cleaned LateralGM Preferences.");
	}
}