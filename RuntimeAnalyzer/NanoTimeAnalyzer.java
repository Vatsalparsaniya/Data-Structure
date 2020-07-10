package com.wordpress.viscerali.util.timeanalyzer;
/**
 * @author Jagreet Das Gupta
 */
import java.util.concurrent.TimeUnit;
//TODO : Optimization deduction required
public class NanoTimeAnalyzer implements TimeAnalyzer {

	private long startTime = 0, stopTime = 0, pauseTime = 0, elapsedTime = 0, refTime = 0;
	private static int count = 0;
	private String name = "Default-Analyzer"+count++;
	protected boolean paused = false, stopped = false;
	//private TimeAnalyzer ta = new NanoTimeAnalyzer();

	public NanoTimeAnalyzer() {/*ta.start();*/}

	public NanoTimeAnalyzer(String s) {
		//ta.start();
		//try{
		name = s;
		return;
		//}
		//finally{ta.pause();}
	}

	@Override
	public String toString(){
		//ta.resume();
		//try{
		return this.getClass().getSimpleName()+" : "+name;
		//}
		//finally{ta.pause();}
	}
	
	@Override
	public Object elapsed() {
		return this.elapsedTime;
	}
	
	@Override
	public void setElapsed(Object time) {
       this.elapsedTime=(long)time;
	}

	@Override
	public void start() throws TimeAnalyzerException {
		//ta.resume();
		//try{
		if(startTime!=0) throw new TimeAnalyzerException(this.toString()+" already started");
		startTime = System.nanoTime();
		//}
		//finally{ta.pause();}
	}

	@Override
	public boolean pause() throws TimeAnalyzerException {
		//ta.resume();
		//try{
		if(stopped)	throw new TimeAnalyzerException(this.toString()+" has been stopped");
		if(paused) return false;
		return paused=true;
		//}
		//finally{ta.pause();}
	}

	@Override
	public boolean resume() throws TimeAnalyzerException {
		//ta.resume();
		//try{
		long time = System.nanoTime()-refTime;
		if(!paused)
			return false;
		if(stopped) throw new TimeAnalyzerException(this.toString()+" has been stopped");
		pauseTime+=time;
		paused = false;
		return true;
		//}
		//finally{ta.pause();}
	}

	@Override
	public void stop() throws TimeAnalyzerException {
		//ta.resume();
		//try{
		if(stopped) throw new TimeAnalyzerException(this.toString()+" already stopped");
		stopTime = System.nanoTime();
		elapsedTime += stopTime-(startTime+pauseTime);
		stopped = true;
		//}
		//finally{ta.pause();}
	}
	@Override
	public String getElapsedTime(TimeUnit unit) throws TimeAnalyzerException {
		//ta.resume();
		//try{
		if(!stopped){
			return null;
		}
		return Long.toString(unit.convert(elapsedTime, TimeUnit.NANOSECONDS))+" "+unit.toString().toLowerCase();
		//}
		//finally{ta.pause();}
	}

	@Override
	public String getPausedTime(TimeUnit unit) throws TimeAnalyzerException {
		return Long.toString(unit.convert(pauseTime, TimeUnit.NANOSECONDS))+" "+unit.toString().toLowerCase();
	}


}
