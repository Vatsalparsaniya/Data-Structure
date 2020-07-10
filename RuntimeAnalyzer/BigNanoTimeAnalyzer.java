package com.wordpress.viscerali.util.timeanalyzer;
/**
 * @author Jagreet Das Gupta
 */
import java.util.concurrent.TimeUnit;
import java.math.BigInteger;
//TODO : Optimization deduction required
public class BigNanoTimeAnalyzer implements TimeAnalyzer {
    private static final BigInteger ZERO = new BigInteger("0");
	private BigInteger startTime = ZERO, stopTime = ZERO, pauseTime = ZERO, elapsedTime = ZERO, refTime = ZERO;
	private static int count = 0;
	private String name = "Default-Analyzer"+count++;
	protected boolean paused = false, stopped = false;
	//private TimeAnalyzer ta = new NanoTimeAnalyzer();

	public BigNanoTimeAnalyzer() {/*ta.start();*/}

	public BigNanoTimeAnalyzer(String s) {
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
       this.elapsedTime=(BigInteger)time;
	}

	@Override
	public void start() throws TimeAnalyzerException {
		//ta.resume();
		//try{
		if(startTime!=ZERO) throw new TimeAnalyzerException(this.toString()+" already started");
		startTime = new BigInteger(Long.toString(System.nanoTime()));
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
		BigInteger time = new BigInteger(Long.toString(System.nanoTime())).subtract(refTime);
		if(!paused)
			return false;
		if(stopped) throw new TimeAnalyzerException(this.toString()+" has been stopped");
		pauseTime=pauseTime.add(time);
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
		stopTime = new BigInteger(Long.toString(System.nanoTime()));
		elapsedTime = elapsedTime.add(stopTime.subtract(startTime.add(pauseTime)));
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
		return Long.toString(unit.convert(elapsedTime.longValueExact(), TimeUnit.NANOSECONDS))+" "+unit.toString().toLowerCase();
		//}
		//finally{ta.pause();}
	}

	@Override
	public String getPausedTime(TimeUnit unit) throws TimeAnalyzerException {
		return Long.toString(unit.convert(pauseTime.longValueExact(), TimeUnit.NANOSECONDS))+" "+unit.toString().toLowerCase();
	}

}
