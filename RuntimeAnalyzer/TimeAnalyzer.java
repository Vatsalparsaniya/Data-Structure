package com.wordpress.viscerali.util.timeanalyzer;
/**
 * @author Jagreet Das Gupta
 */
import java.util.concurrent.TimeUnit;

public interface TimeAnalyzer {
	public void start() throws TimeAnalyzerException;
	public boolean pause() throws TimeAnalyzerException;
	public boolean resume() throws TimeAnalyzerException;
	public void stop() throws TimeAnalyzerException;
	Object elapsed();
	void setElapsed(Object time);
	public String getElapsedTime(TimeUnit unit) throws TimeAnalyzerException;
	public String getPausedTime(TimeUnit unit) throws TimeAnalyzerException;
}
